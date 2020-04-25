#pragma once

#include <QtWidgets/QWidget>
#include <QVector>
#include "ui_MiniSudoCalc.h"

typedef QVector<QVector<int>>  DvecArray;			/// < ����һ����ά��������

class MiniSudoCalc : public QWidget
{
	Q_OBJECT

public:
	MiniSudoCalc(QWidget *parent = Q_NULLPTR);

protected slots:
	//* @brief : ɾ����ť���
	void onDelBtnClicked();
	//* @brief : ��հ�ť���
	void onClearBtnClicked();
	//* @brief : ���㰴ť���
	void onStartBtnClicked();
	//* @brief : ��ǰ�����item�ı�ۺ���
	//* @param [in] : current: ��ǰitem
	//* @param [in] : previous: ǰһ��item
	void onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous);
	
private:
	//* @brief : У���ֵ�ڴ�λ���Ƿ����Ҫ��
	//* @param [in] : num: ��ֵ
	//* @param [in] : row: ����
	//* @param [in] : col: ����
	//* @return true: ����Ҫ��, false: ������Ҫ��
	bool isValidNum(int num, int row, int col);
	//* @brief : ���ݷ�����ÿ��λ�õ�ֵ
	//* @param [in] :  row: ��ǰ���������
	//* @param [in] : col: ��ǰ���������
	//* @return true:  ����ɹ�  false: ����ʧ��
	bool backTrack(int row, int col);
	//* @brief : ���ð�ť�Ƿ����
	//* @param [in] : enable:�Ƿ����
	void setBtnEnable(bool enable);


private:
	Ui::MiniSudokuCalcClass ui;
	DvecArray				m_nArrayDate;			/// < ��ά�������ڴ洢��������
	bool					m_bStartAutoCalc;		/// < ���ڼ�¼�Ƿ�ʼ�Զ�����
	bool					m_bShowAnimation;		/// < ���ڼ�¼�Ƿ񶯻���ʾ
};
