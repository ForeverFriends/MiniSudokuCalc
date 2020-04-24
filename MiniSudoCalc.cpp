#include "MiniSudoCalc.h"

const int G_SizeNum = 9;

MiniSudoCalc::MiniSudoCalc(QWidget *parent)
	: QWidget(parent),m_nArrayDate(DvecArray(G_SizeNum,QVector<int>(G_SizeNum,0)))
{
	ui.setupUi(this);
	ui.pSudoWnd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.pSudoWnd->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	
	// 
	connect(ui.pDel, &QPushButton::clicked, this, &MiniSudoCalc::onDelBtnClicked);
	connect(ui.pClear, &QPushButton::clicked, this, &MiniSudoCalc::onClearBtnClicked);
	connect(ui.pStart, &QPushButton::clicked, this, &MiniSudoCalc::onStartBtnClicked);
	connect(ui.pSudoWnd, &QTableWidget::currentItemChanged, this, &MiniSudoCalc::onCurrentItemChanged);
}

void MiniSudoCalc::onDelBtnClicked()
{

}

void MiniSudoCalc::onClearBtnClicked()
{

}

void MiniSudoCalc::onStartBtnClicked()
{

}

void MiniSudoCalc::onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous)
{
	
}

