/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineBlockData.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/02/06 16:30:44
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "MineBlockData.h"


CMineBlockData::CMineBlockData()
	: m_eMineStatus(E_STATE_CLOSE)
	, m_nMineCnt(-1)
	, m_bIsMine(false)
	, m_nRow(0)
	, m_nCol(0)
{
}


CMineBlockData::~CMineBlockData()
{
}

void CMineBlockData::OpenBlock()
{
	SetBlockState(E_STATE_OPEN);
}

void CMineBlockData::SetAdjoinMine(int nCnt)
{
	m_nMineCnt = nCnt;
}

int CMineBlockData::GetAdjoinMineCnt()
{
	return m_nMineCnt;
}

void CMineBlockData::SetBlockState(EBlockState state)
{
	m_eMineStatus = state;
}

EBlockState CMineBlockData::GetBlockState()
{
	return m_eMineStatus;
}

bool CMineBlockData::IsMine() const
{
	return m_bIsMine;
}

void CMineBlockData::SetMine(bool bIsMine)
{
	m_bIsMine = bIsMine;
}

void CMineBlockData::SetRow(int nRow)
{
	m_nRow = nRow;
}

void CMineBlockData::SetColumn(int nCol)
{
	m_nCol = nCol;
}

int CMineBlockData::GetRow()
{
	return m_nRow;
}

int CMineBlockData::GetColumn()
{
	return m_nCol;
}
