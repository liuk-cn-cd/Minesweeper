/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: MineScene.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/02/06 16:30:58
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "MineScene.h"
#include "MineBlock.h"
#include "MineBlockData.h"
#include "MineSweeperMgr.h"

CMineScene::CMineScene(QObject *parent)
	: QGraphicsScene(parent)
{
	setBackgroundBrush(Qt::white);
}

CMineScene::~CMineScene()
{

}

void CMineScene::RestartGame()
{
	this->clear();
	int nCol = MineSweerMgrIns.GetColumnCount();
	int nRow = MineSweerMgrIns.GetRowCount();

	for (int i = 0; i < nRow; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			CMineBlockData* pBlockData = MineSweerMgrIns.GetBlock(i, j);
			CMineBlock* pBlockItem = new CMineBlock;
			pBlockItem->SetBlockData(pBlockData);
			connect(pBlockItem, SIGNAL(SigBlockOpen(int,int))
				, this, SLOT(SlotBlockOpen(int,int)));
			this->addItem(pBlockItem);
		}
	}
}

void CMineScene::SlotBlockOpen(int nRow, int nCol)
{
	if (MineSweerMgrIns.GameState() == E_GAME_WIN || MineSweerMgrIns.GameState() == E_GAME_LOSE)
	{
		return;
	}
	MineSweerMgrIns.OpenBlock(nRow, nCol);
	update();
}
