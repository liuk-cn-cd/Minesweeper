/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineBlock.h
 * @brief	: 藏雷方块UI对象声明 
 * @author	: liuk
 * @date	: 2017/02/06 16:14:49
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef MINEBLOCK_H
#define MINEBLOCK_H

#include <QGraphicsItem>
#include <QTime>
#include <QObject>
#include "DataDefine.h"
class CMineBlockData;
/*!
 * @class	: CMineBlock
 * @brief	: 藏雷方块item
 * @author	: liuk
 * @date	: 2017/02/06 16:15
 */
class CMineBlock :public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	CMineBlock(QGraphicsItem *parent = NULL);
	~CMineBlock();
public:
	void SetBlockData(CMineBlockData* pBlockData);
	
private:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = Q_NULLPTR */);
	
	virtual QRectF boundingRect() const;

	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	/**
	 * @fn		: DrawOpenBlock
	 * @brief	: 绘制打开的方块
	 * @access	: private 
	 * @param	: QPainter * painter
	 * @param	: const QStyleOptionGraphicsItem * option
	 * @return	: void
	 */
	void DrawOpenBlock(QPainter *painter, const QStyleOptionGraphicsItem *option);
	
	/**
	 * @fn		: DrawCloseBlock
	 * @brief	: 绘制关闭的方块
	 * @access	: private 
	 * @param	: QPainter * painter
	 * @param	: const QStyleOptionGraphicsItem * option
	 * @return	: void
	 */
	void DrawCloseBlock(QPainter *painter, const QStyleOptionGraphicsItem *option);
	
	/**
	 * @fn		: DrawMarkMine
	 * @brief	: 绘制标记为地雷的方块
	 * @access	: private 
	 * @param	: QPainter * painter
	 * @param	: const QStyleOptionGraphicsItem * option
	 * @return	: void
	 */
	void DrawMarkMine(QPainter *painter, const QStyleOptionGraphicsItem *option);

	/**
	 * @fn		: DrawMarkUnde
	 * @brief	: 绘制标记为未知的方块
	 * @access	: private 
	 * @param	: QPainter * painter
	 * @param	: const QStyleOptionGraphicsItem * option
	 * @return	: void
	 */
	void DrawMarkUnde(QPainter *painter, const QStyleOptionGraphicsItem *option);

	/**
	 * @fn		: GetTextColorByMineCnt
	 * @brief	: 根据地雷数量获取文本颜色
	 * @access	: private 
	 * @param	: int nMineCnt
	 * @return	: QT_NAMESPACE::QColor
	 */
	QColor GetTextColorByMineCnt(int nMineCnt);

	void OnMouseClicked();

signals:
	//单击事件
	void SigBlockOpen(int nRow, int nCol);
private:
	CMineBlockData* m_pBlockData;
	// 单击计时器
	QTime m_tmClick;
};

#endif // MINEBLOCK_H
