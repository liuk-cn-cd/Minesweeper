/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineSweeperMgr.cpp
 * @brief	: 游戏数据管理实现
 * @author	: liuk
 * @date	: 2017/02/06 16:27:54
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "MineSweeperMgr.h"
#include "MineBlockData.h"
#include <QTime>

CMineSweeperMgr* CMineSweeperMgr::m_pInstance = nullptr;

CMineSweeperMgr* CMineSweeperMgr::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CMineSweeperMgr;
	}
	return m_pInstance;
}

void CMineSweeperMgr::ExitInstance()
{
	if(nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CMineSweeperMgr::InitGame()
{
	Clear();

	for (int i = 0; i < m_nRowCnt; i++)
	{
		for (int j = 0; j < m_nColCnt; j++)
		{
			short sKey = CovertKey(i, j);
			m_arrNoAllocBlock.push_back(sKey);
			CMineBlockData* pBlock = new CMineBlockData;
			pBlock->SetColumn(j);
			pBlock->SetRow(i);
			m_mapMineMat[sKey] = pBlock;
			pBlock->SetMine(false);
			pBlock->SetBlockState(E_STATE_CLOSE);
		}
	}

	m_nOverBlock = m_nColCnt * m_nRowCnt - m_nMineCnt;
	m_eGameState = E_GAME_NOBEG;
}

CMineSweeperMgr::CMineSweeperMgr()
	: m_nOverBlock(0)
	, m_eGameState(E_GAME_NOBEG)
	, m_eGameModel(E_GAME_TURN_MODEL)
{
	qsrand(QTime::currentTime().msec());
}


CMineSweeperMgr::~CMineSweeperMgr()
{
}

CMineBlockData* CMineSweeperMgr::GetBlock(int nRow, int nCol)
{
	short sKey = CovertKey(nRow, nCol);
	std::map<short, CMineBlockData*>::iterator itr = m_mapMineMat.find(sKey);
	if (m_mapMineMat.end() == itr)
	{
		return nullptr;
	}
	return itr->second;
}

void CMineSweeperMgr::StartGame(int nRow, int nCol)
{
	InitMine(nRow, nCol);
	InitBlock();
	m_eGameState = E_GAME_IN;
	NormalOpenBlock(nRow, nCol);
	m_tmGameClock.restart();
	UpdateGameProgress();
}

void CMineSweeperMgr::TurnBlock(int nRow, int nCol)
{
	CMineBlockData* pBlockData = GetBlock(nRow, nCol);
	if (NULL == pBlockData)
	{
		return;
	}
	if (pBlockData->IsMine())
	{
		return;
	}
	if (pBlockData->GetBlockState() == E_STATE_OPEN)
	{
		return;
	}

	pBlockData->OpenBlock();
	m_nOverBlock--;

	if (pBlockData->GetAdjoinMineCnt() > 0)
	{
		return;
	}
	TurnBlock(nRow - 1, nCol);
	TurnBlock(nRow - 1, nCol - 1);
	TurnBlock(nRow - 1, nCol + 1);
	TurnBlock(nRow, nCol - 1);
	TurnBlock(nRow, nCol + 1);
	TurnBlock(nRow + 1, nCol - 1);
	TurnBlock(nRow + 1, nCol + 1);
	TurnBlock(nRow + 1, nCol);
}

void CMineSweeperMgr::LostGame()
{
	for (std::map<short, CMineBlockData*>::iterator itr = m_mapMineMat.begin()
		; itr != m_mapMineMat.end(); ++itr)
	{
		CMineBlockData* pBlockData = itr->second;
		if (NULL == pBlockData)
		{
			continue;
		}
		if (pBlockData->IsMine())
		{
			pBlockData->OpenBlock();
		}
	}
	m_eGameState = E_GAME_LOSE;
	emit SigGameLost();
}

EGameState CMineSweeperMgr::GameState()
{
	return m_eGameState;
}

int CMineSweeperMgr::GetGameTime()
{
	return m_tmGameClock.elapsed();
}

int CMineSweeperMgr::CalcMarkCount(int nRow, int nCol)
{
	int nMarkCnt = 0;

	CMineBlockData* pLeftBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFT);
	if (NULL != pLeftBlock)
	{
		if (pLeftBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	CMineBlockData* pRightBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHT);
	if (NULL != pRightBlock)
	{
		if (pRightBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	CMineBlockData* pTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_TOP);
	if (NULL != pTopBlock)
	{
		if (pTopBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}


	CMineBlockData* pBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_BOTTOM);
	if (NULL != pBottomBlock)
	{
		if (pBottomBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}


	CMineBlockData* pLeftTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFTTOP);
	if (NULL != pLeftTopBlock)
	{
		if (pLeftTopBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	CMineBlockData* pLeftBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFTBOTTOM);
	if (NULL != pLeftBottomBlock)
	{
		if (pLeftBottomBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	CMineBlockData* pRighttTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHTTOP);
	if (NULL != pRighttTopBlock)
	{
		if (pRighttTopBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	CMineBlockData* pRightBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHTBOTTOM);
	if (NULL != pRightBottomBlock)
	{
		if (pRightBottomBlock->GetBlockState() == E_STATE_MARK_MINE)
			nMarkCnt++;
	}

	return nMarkCnt;
}

void CMineSweeperMgr::ChangeGameModel(EGameModel eGameModel)
{
	m_eGameModel = eGameModel;
}

EGameModel CMineSweeperMgr::GameModel()
{
	return m_eGameModel;
}

void CMineSweeperMgr::SetRowCounts(int nRows)
{
	m_nRowCnt = nRows;
}

void CMineSweeperMgr::SetColCounts(int nCols)
{
	m_nColCnt = nCols;
}

void CMineSweeperMgr::SetMineCount(int nMineCnt)
{
	m_nMineCnt = nMineCnt;
}

CMineBlockData* CMineSweeperMgr::GetAdjoinBlock(int nRow, int nCol, EAdjoinPlace ePlace)
{
	int nAdjoinRow = nRow;
	int nAdjoinCol = nCol;
	if((ePlace & E_ADJOIN_LEFT) != 0)
	{
		nAdjoinCol--;
	}
	else if((ePlace & E_ADJOIN_RIGHT) != 0)
	{
		nAdjoinCol++;
	}

	if ((ePlace & E_ADJOIN_TOP) != 0)
	{
		nAdjoinRow--;
	}
	else if ((ePlace & E_ADJOIN_BOTTOM) != 0)
	{
		nAdjoinRow++;
	}

	short sKey = CovertKey(nAdjoinRow, nAdjoinCol);
	if(m_mapMineMat.find(sKey) == m_mapMineMat.end())
	{
		return NULL;
	}

	return m_mapMineMat[sKey];
}

void CMineSweeperMgr::InitMine(int nBegRow, int nBegCol)
{
	int nOverMine = m_nMineCnt;
	short sInitKey = CovertKey(nBegRow, nBegCol);
	while (nOverMine > 0)
	{
		int nIndex = qrand() % m_arrNoAllocBlock.size();

		short sKey = m_arrNoAllocBlock[nIndex];
		// 初始化点
		if (sKey == sInitKey)
		{
			m_arrNoAllocBlock.erase(m_arrNoAllocBlock.begin() + nIndex);
			continue;
		}
		
		
		if (m_mapMineMat.find(sKey) == m_mapMineMat.end())
		{
			continue;
		}

		CMineBlockData* pBlockData = m_mapMineMat[sKey];
		if (NULL == pBlockData)
		{
			continue;
		}

		// 已经设为地雷了
		if (pBlockData->IsMine())
		{
			continue;
		}

		
		// 设置成地雷
		pBlockData->SetMine(true);
		m_arrNoAllocBlock.erase(m_arrNoAllocBlock.begin() + nIndex);
		nOverMine--;
	}
}

void CMineSweeperMgr::InitBlock()
{
	for (int i = 0; i < m_nRowCnt; i++)
	{
		for (int j = 0; j < m_nColCnt; j++)
		{
			short sKey = CovertKey(i, j);
			
			if (m_mapMineMat.find(sKey) == m_mapMineMat.end())
			{
				continue;
			}
			CMineBlockData* pBlock = m_mapMineMat[sKey];

			pBlock->SetAdjoinMine(CalcMineCnt(i, j));
		}
	}
}

int CMineSweeperMgr::CalcMineCnt(int nRow, int nCol)
{
	int nMineCntRet = 0;

	CMineBlockData* pLeftBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFT);
	if (NULL != pLeftBlock)
	{
		if(pLeftBlock->IsMine())
			nMineCntRet++;
	}

	CMineBlockData* pRightBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHT);
	if (NULL != pRightBlock)
	{
		if (pRightBlock->IsMine())
			nMineCntRet++;
	}

	CMineBlockData* pTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_TOP);
	if (NULL != pTopBlock)
	{
		if (pTopBlock->IsMine())
			nMineCntRet++;
	}


	CMineBlockData* pBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_BOTTOM);
	if (NULL != pBottomBlock)
	{
		if (pBottomBlock->IsMine())
			nMineCntRet++;
	}


	CMineBlockData* pLeftTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFTTOP);
	if (NULL != pLeftTopBlock)
	{
		if (pLeftTopBlock->IsMine())
			nMineCntRet++;
	}

	CMineBlockData* pLeftBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_LEFTBOTTOM);
	if (NULL != pLeftBottomBlock)
	{
		if (pLeftBottomBlock->IsMine())
			nMineCntRet++;
	}

	CMineBlockData* pRighttTopBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHTTOP);
	if (NULL != pRighttTopBlock)
	{
		if (pRighttTopBlock->IsMine())
			nMineCntRet++;
	}

	CMineBlockData* pRightBottomBlock = GetAdjoinBlock(nRow, nCol, E_ADJOIN_RIGHTBOTTOM);
	if (NULL != pRightBottomBlock)
	{
		if (pRightBottomBlock->IsMine())
			nMineCntRet++;
	}

	return nMineCntRet;
}

void CMineSweeperMgr::Clear()
{
	for (std::map<short, CMineBlockData*>::iterator itr = m_mapMineMat.begin()
		; itr != m_mapMineMat.end(); ++itr)
	{
		CMineBlockData* pBlockData = itr->second;
		if (NULL != pBlockData)
		{
			delete pBlockData;
			pBlockData = NULL;
		}
	}
	m_mapMineMat.clear();
	m_arrNoAllocBlock.clear();
}

int CMineSweeperMgr::GetColumnCount() const
{
	return m_nColCnt;
}

int CMineSweeperMgr::GetRowCount() const
{
	return m_nRowCnt;
}

void CMineSweeperMgr::OpenBlock(int nRow, int nCol)
{
	int nNoMineBlockCnt = m_nColCnt * m_nRowCnt - m_nMineCnt;
	// 第一次翻开方块
	if (m_nOverBlock == nNoMineBlockCnt)
	{
		StartGame(nRow, nCol);
		return;
	}
	if (m_eGameModel == E_GAME_FLAG_MODEL)
	{
		QuickOpenBlock(nRow, nCol);
	}
	else
	{
		NormalOpenBlock(nRow, nCol);
	}

	UpdateGameProgress();

}

void CMineSweeperMgr::UpdateGameProgress()
{
	int nNoMineBlockCnt = m_nColCnt * m_nRowCnt - m_nMineCnt;
	double dProgress = 100.0 * (nNoMineBlockCnt* 1.0 - m_nOverBlock * 1.0) / nNoMineBlockCnt;
	emit SigProgress(dProgress);
	if (m_nOverBlock == 0)
	{
		WinGame();
	}
}

void CMineSweeperMgr::NormalOpenBlock(int nRow, int nCol)
{
	CMineBlockData* pBlockData = GetBlock(nRow, nCol);
	if (NULL == pBlockData)
	{
		return;
	}

	if (pBlockData->IsMine())
	{
		LostGame();
		return;
	}
	TurnBlock(nRow, nCol);
}

void CMineSweeperMgr::WinGame()
{
	m_eGameState = E_GAME_WIN;
	emit SigGameWin();
}

void CMineSweeperMgr::QuickOpenBlock(int nRow, int nCol)
{
	CMineBlockData* pBlockData = GetBlock(nRow, nCol);
	if (NULL == pBlockData)
	{
		return;
	}
	if (pBlockData->GetBlockState() != E_STATE_OPEN)
	{
		return;
	}

	// 如果标记的数目等于目标格子周围实际的地雷数目，则翻开其周围所有未翻开的格子
	if (CalcMineCnt(nRow, nCol) != CalcMarkCount(nRow, nCol))
	{
		return;
	}
	// 翻开周围8个方块
	StrongOpenBlock(nRow - 1, nCol);
	StrongOpenBlock(nRow - 1, nCol - 1);
	StrongOpenBlock(nRow - 1, nCol + 1);
	StrongOpenBlock(nRow, nCol - 1);
	StrongOpenBlock(nRow, nCol + 1);
	StrongOpenBlock(nRow + 1, nCol - 1);
	StrongOpenBlock(nRow + 1, nCol + 1);
	StrongOpenBlock(nRow + 1, nCol);

}

void CMineSweeperMgr::StrongOpenBlock(int nRow, int nCol)
{
	CMineBlockData* pBlockData = GetBlock(nRow, nCol);
	if (NULL == pBlockData)
	{
		return;
	}

	if (pBlockData->GetBlockState() == E_STATE_MARK_MINE)
	{
		return;
	}

	if (pBlockData->IsMine())
	{
		LostGame();
		return;
	}
	// 翻开周围8个方块
	TurnBlock(nRow, nCol);
}

