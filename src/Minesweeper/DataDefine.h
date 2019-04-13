/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: DataDefine.h
 * @brief	: 数据定义，定义一些用到的枚举、简单数据结构
 * @author	: liuk
 * @date	: 2017/02/06 16:13:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _DATADEFINE_H
#define _DATADEFINE_H
enum EBlockState
{
	E_STATE_CLOSE	  = 0x01,	// 方块关闭的
	E_STATE_OPEN	  = 0x02,	// 方块打开的
	E_STATE_MARK_MINE = 0x03,	// 标记为地雷
	E_STATE_MARK_UNDE = 0x04	// 标记为未知(问号)
};

enum EGameState
{
	E_GAME_LOSE		= 0x01,	// 游戏失败
	E_GAME_WIN		= 0x02, // 游戏胜利
	E_GAME_IN		= 0x03,	// 游戏中
	E_GAME_NOBEG	= 0x04,	// 游戏未开始
};
// 游戏模式
enum EGameModel
{
	E_GAME_TURN_MODEL = 0x01, // 翻开模式
	E_GAME_FLAG_MODEL = 0x02, // 插旗模式
};
// 相邻位置
enum EAdjoinPlace
{
	E_ADJOIN_TOP	 = 0x01,
	E_ADJOIN_LEFT	 = 0x02,
	E_ADJOIN_RIGHT	 = 0x04,
	E_ADJOIN_BOTTOM	 = 0x08,
	E_ADJOIN_LEFTTOP	 = E_ADJOIN_LEFT | E_ADJOIN_TOP,
	E_ADJOIN_LEFTBOTTOM	 = E_ADJOIN_LEFT | E_ADJOIN_BOTTOM,
	E_ADJOIN_RIGHTTOP	 = E_ADJOIN_RIGHT| E_ADJOIN_TOP,
	E_ADJOIN_RIGHTBOTTOM = E_ADJOIN_RIGHT| E_ADJOIN_BOTTOM
};
#define CovertRowIndex(num) (((num) >> 8) & 0X00FF)
#define CovertColIndex(num) ((num) & 0X00FF)
#define CovertKey(row, col) ((((short)(row)) << 8) & 0XFF00) | ((short)(col) & 0X00FF)
#endif // _DATADEFINE_H