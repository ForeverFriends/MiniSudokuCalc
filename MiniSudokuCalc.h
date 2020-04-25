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
	//* @brief : 校验该值在此位置是否符合要求
	//* @param [in] : num: 数值
	//* @param [in] : row: 行数
	//* @param [in] : col: 列数
	//* @return true: 符合要求, false: 不符合要求
	bool isValidNum(int num, int row, int col);
	//* @brief : 回溯法计算每个位置的值
	//* @param [in] :  row: 当前计算的行数
	//* @param [in] : col: 当前计算的列数
	//* @return true:  计算成功  false: 计算失败
	bool backTrack(int row, int col);
	//* @brief : 设置按钮是否可用
	//* @param [in] : enable:是否可用
	void setBtnEnable(bool enable);


private:
	Ui::MiniSudokuCalcClass ui;
	DvecArray				m_nArrayDate;			/// < 二维数组用于存储具体数据
	bool					m_bStartAutoCalc;		/// < 用于记录是否开始自动计算
	bool					m_bShowAnimation;		/// < 用于记录是否动画显示
};
