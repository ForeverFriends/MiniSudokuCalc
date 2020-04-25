#include "MiniSudokuCalc.h"
#include <QTime>
#include <QMessageBox>

const int G_SizeNum = 9;
const int G_nFixpixSize = 50;			/// < ���õļ�������ݵĴ�С

MiniSudoCalc::MiniSudoCalc(QWidget* parent)
	: QWidget(parent), m_nArrayDate(DvecArray(G_SizeNum, QVector<int>(G_SizeNum, 0))), m_bStartAutoCalc(false),
	m_bShowAnimation(false)
{
	ui.setupUi(this);
	ui.pSudoWnd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.pSudoWnd->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	for (int row = 0; row < G_SizeNum; ++row)
	{
		for (int col = 0; col < G_SizeNum; ++col)
		{
			QTableWidgetItem* item = new QTableWidgetItem;
			item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.pSudoWnd->setItem(row, col, item);
		}
	}
	onCurrentItemChanged(ui.pSudoWnd->item(0, 0), ui.pSudoWnd->item(0, 0)); // Ĭ��ѡ�е�һ�е�һ��
	// 
	connect(ui.pDel, &QPushButton::clicked, this, &MiniSudoCalc::onDelBtnClicked);
	connect(ui.pClear, &QPushButton::clicked, this, &MiniSudoCalc::onClearBtnClicked);
	connect(ui.pStart, &QPushButton::clicked, this, &MiniSudoCalc::onStartBtnClicked);
	connect(ui.checkBox, &QCheckBox::stateChanged, this, [&](int state) {m_bShowAnimation = state == Qt::Checked; });
	connect(ui.pSudoWnd, &QTableWidget::currentItemChanged, this, &MiniSudoCalc::onCurrentItemChanged);
}

void MiniSudoCalc::onDelBtnClicked()
{
	ui.pSudoWnd->currentItem()->setText(QString(""));
	ui.pSudoWnd->currentItem()->setFont(this->font());
	m_nArrayDate[ui.pSudoWnd->currentRow()][ui.pSudoWnd->currentColumn()] = 0;
}

void MiniSudoCalc::onClearBtnClicked()
{
	m_bStartAutoCalc = false;
	for (int row = 0; row < G_SizeNum; ++row)
	{
		for (int col = 0; col < G_SizeNum; ++col)
		{
			m_nArrayDate[row][col] = 0;
			ui.pSudoWnd->item(row, col)->setText(QString(""));
			ui.pSudoWnd->item(row, col)->setFont(this->font());
		}
	}
}

void MiniSudoCalc::onStartBtnClicked()
{
	m_bStartAutoCalc = true;
	setBtnEnable(false);
	for (int row = 0; row < G_SizeNum; ++row)
	{
		for (int col = 0; col < G_SizeNum; ++col)
		{
			if (m_nArrayDate[row][col] != 0 && !isValidNum(m_nArrayDate[row][col], row, col))
			{
				ui.pSudoWnd->setCurrentCell(row, col);
				QMessageBox::critical(this, QString::fromLocal8Bit("����"),
					QString::fromLocal8Bit("��%1�У���%2����%3�����Ϲ���").
					arg(row + 1).arg(col + 1).arg(m_nArrayDate[row][col]));
				setBtnEnable(true);
				return;
			}
		}
	}
	if (backTrack(0, 0) &&!m_bShowAnimation)
	{
		
		for (int row = 0; row < G_SizeNum; ++row)
		{
			for (int col = 0; col < G_SizeNum; col++)
			{
				ui.pSudoWnd->item(row, col)->setText(QString::number(m_nArrayDate[row][col]));
			}
		}
	}
	setBtnEnable(true);
}

void MiniSudoCalc::onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous)
{
	if (current == nullptr || previous == nullptr)
	{
		return;
	}
	if (previous->text().isEmpty())
	{
		// ������ɾ���ĸ���
		m_nArrayDate[previous->row()][previous->column()] = 0;
		previous->setFont(this->font()); // ���δ�������ݣ����û�Ĭ������
	}
	else if (!m_bStartAutoCalc)
	{
		QFont newFont;
		newFont.setPixelSize(G_nFixpixSize);
		previous->setFont(newFont);
		m_nArrayDate[previous->row()][previous->column()] = previous->text().toUInt();
	}

	
	for (int i = 0; i < G_SizeNum; ++i)
	{
		ui.pSudoWnd->item(previous->row(), i)->setBackgroundColor(Qt::white);
		ui.pSudoWnd->item(i, previous->column())->setBackgroundColor(Qt::white);
	}
	for (int i = 0; i < G_SizeNum; ++i)
	{
		ui.pSudoWnd->item(current->row(), i)->setBackgroundColor(Qt::lightGray);
		ui.pSudoWnd->item(i, current->column())->setBackgroundColor(Qt::lightGray);
	}
}

bool MiniSudoCalc::isValidNum(int num, int row, int col)
{
	if (num < 1 || num > G_SizeNum || row < 0 || row >= G_SizeNum || col < 0 || col > G_SizeNum) return false;
	// �жϸ�λ���Ƿ���ֵ�����ڿ�ʼ֮ǰ��У��ʹ��
	bool isChanged = false;
	if (m_nArrayDate[row][col] == num)
	{
		m_nArrayDate[row][col] = 0;
		isChanged = true;
	}
	bool isValid = true;
	for (int i = 0; i < G_SizeNum; ++i)
	{
		if (m_nArrayDate[row][i] == num || m_nArrayDate[i][col] == num)
		{
			isValid = false;
			break;
		}
		else if (m_nArrayDate[(row/3)*3 + i/3][(col/3)*3 + i%3] == num)
		{
			isValid = false;
			break;
		}
	}
	isChanged ?	m_nArrayDate[row][col] = num : 0;
	return isValid;
}

bool MiniSudoCalc::backTrack(int row, int col)
{
	if (col >= G_SizeNum) // ����
	{
		return backTrack(row + 1, 0);
	}

	if (row >= G_SizeNum) // ��������,���
	{
		return true;
	}
	for (int i = row; i < G_SizeNum; ++i)
	{
		for (int j = col; j < G_SizeNum; j++)
		{
			if (m_nArrayDate[i][j] != 0)
			{
				return backTrack(i, j + 1);
			}
			for (int num = 1; num <= G_SizeNum; ++num)
			{
				if (isValidNum(num, i, j))
				{
					m_nArrayDate[i][j] = num;
					if (m_bShowAnimation)
					{
						ui.pSudoWnd->item(i, j)->setText(QString::number(num));
						ui.pSudoWnd->setCurrentItem(ui.pSudoWnd->item(i, j));
						// ��ʱ��ʾ�����ڲ鿴����
						QTime time;
						time.start();
						while (time.elapsed() < 100)
						{
							QCoreApplication::processEvents();
						}
					}
					if (backTrack(i, j + 1))
					{
						return true;
					}
					m_nArrayDate[i][j] = 0;
					if (m_bShowAnimation)
					{
						ui.pSudoWnd->item(i, j)->setText(QString(""));
						ui.pSudoWnd->setCurrentItem(ui.pSudoWnd->item(i, j));
					}
				}
			}
			return false;
		}
	}

	return false;
}

void MiniSudoCalc::setBtnEnable(bool enable)
{
	ui.pStart->setEnabled(enable);
	ui.pDel->setEnabled(enable);
	ui.pClear->setEnabled(enable);
}

