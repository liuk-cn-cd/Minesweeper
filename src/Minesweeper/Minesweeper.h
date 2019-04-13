/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: Minesweeper.h
 * @brief	: 扫雷游戏主窗口
 * @author	: liuk
 * @date	: 2017/02/06 16:20:16
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QtWidgets/QMainWindow>
#include "ui_Minesweeper.h"
class CMineScene;
class Minesweeper : public QMainWindow
{
	Q_OBJECT

public:
	Minesweeper(QWidget *parent = 0);
	~Minesweeper();
protected:
	virtual void timerEvent(QTimerEvent *event);
protected slots:
	void on_actionOption_triggered();

	void on_ptnNewGame_clicked();

	void on_ptnModel_toggled(bool);

	void SlotGameOver();

	void SlotGameWin();

	void SlotProgress(double dProgress);
	
private:
	Ui::MinesweeperClass ui;
	CMineScene* m_pScene;
	// 刷新时间的定时器
	int m_nTimerId;
};

#endif // MINESWEEPER_H
