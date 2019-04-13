/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: MineBlockData.h
 * @brief	: 藏雷方块数据类，每一个对象关联地图上的一个方块
 * @author	: liuk
 * @date	: 2017/02/06 16:16:10
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _MINEBLOCKDATA_H
#define _MINEBLOCKDATA_H
#include "DataDefine.h"
/*!
 * @class	: CMineBlockData
 * @brief	: 藏雷方块数据类
 * @author	: liuk
 * @date	: 2017/02/06 16:17
 */
class CMineBlockData
{
public:
	CMineBlockData();
	~CMineBlockData();
public:
	/**
	 * @fn		: OpenBlock
	 * @brief	: 打开方块
	 * @access	: public 
	 * @return	: void
	 */
	void OpenBlock();

	/**
	 * @fn		: SetAdjoinMine
	 * @brief	: 设置周围有几个地雷
	 * @access	: public 
	 * @param	: int nCnt
	 * @return	: void
	 */
	void SetAdjoinMine(int nCnt);

	/**
	 * @fn		: GetAdjoinMineCnt
	 * @brief	: 获取周围有几个地雷
	 * @access	: public 
	 * @return	: int
	 */
	int GetAdjoinMineCnt();


	/**
	 * @fn		: SetClockState
	 * @brief	: CMineBlockData::SetBlockState
	 * @access	: public 
	 * @param	: EBlockState state
	 * @return	: void
	 */
	void SetBlockState(EBlockState state);

	/**
	 * @fn		: GetBlockState
	 * @brief	: 获取当前状态
	 * @access	: public 
	 * @return	: EBlockState
	 */
	EBlockState GetBlockState();

	/**
	 * @fn		: IsMine
	 * @brief	: 是否是地雷
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsMine() const;

	/**
	 * @fn		: SetMine
	 * @brief	: 设置成地雷
	 * @access	: public 
	 * @param	: bool bIsMine
	 * @return	: void
	 */
	void SetMine(bool bIsMine);

	/**
	 * @fn		: SetRow
	 * @brief	: 设置行
	 * @access	: public 
	 * @param	: int nRow
	 * @return	: void
	 */
	void SetRow(int nRow);

	/**
	 * @fn		: SetColumn
	 * @brief	: 设置列
	 * @access	: public 
	 * @param	: int nCol
	 * @return	: void
	 */
	void SetColumn(int nCol);

	/**
	 * @fn		: GetRow
	 * @brief	: CMineBlockData::GetRow
	 * @access	: public 
	 * @return	: int
	 */
	int GetRow();

	/**
	 * @fn		: GetColumn
	 * @brief	: CMineBlockData::GetColumn
	 * @access	: public 
	 * @return	: int
	 */
	int GetColumn();
private:
	int m_nMineCnt; // 地雷数。-1为未计算
	EBlockState m_eMineStatus;
	int m_nCol;
	int m_nRow;
	bool m_bIsMine;	//是否是地雷


};

#endif //_MINEBLOCKDATA_H