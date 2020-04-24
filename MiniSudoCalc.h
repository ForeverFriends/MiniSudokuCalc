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
	Ui::MiniSudoCalcClass ui;
	DvecArray				m_nArrayDate;			/// < ��ά�������ڴ洢��������

};
