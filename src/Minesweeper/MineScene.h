/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineScene.h
 * @brief	: 游戏场景类声明
 * @author	: liuk
 * @date	: 2017/02/06 16:17:20
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef MINESCENE_H
#define MINESCENE_H

#include <QGraphicsScene>

/*!
 * @class	: CMineScene
 * @brief	: 扫雷游戏场景
 * @author	: liuk
 * @date	: 2017/02/06 16:18
 */
class CMineScene : public QGraphicsScene
{
	Q_OBJECT

public:
	CMineScene(QObject *parent);
	~CMineScene();

public:
	void RestartGame();
protected slots:
	void SlotBlockOpen(int nRow, int nCol);
	
};

#endif // MINESCENE_H
