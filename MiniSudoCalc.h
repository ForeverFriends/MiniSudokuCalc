#pragma once

#include <QtWidgets/QWidget>
#include <QVector>
#include "ui_MiniSudoCalc.h"

typedef QVector<QVector<int>>  DvecArray;			/// < 声明一个二维数组类型

class MiniSudoCalc : public QWidget
{
	Q_OBJECT

public:
	MiniSudoCalc(QWidget *parent = Q_NULLPTR);

protected slots:
	//* @brief : 删除按钮点击
	void onDelBtnClicked();
	//* @brief : 清空按钮点击
	void onClearBtnClicked();
	//* @brief : 计算按钮点击
	void onStartBtnClicked();
	//* @brief : 当前点击的item改变槽函数
	//* @param [in] : current: 当前item
	//* @param [in] : previous: 前一个item
	void onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous);


private:
	Ui::MiniSudoCalcClass ui;
	DvecArray				m_nArrayDate;			/// < 二维数组用于存储具体数据

};
