/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineSweeperMgr.h
 * @brief	: 扫雷游戏数据管理类声明
 * @author	: liuk
 * @date	: 2017/02/06 16:20:44
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _MINESWEEPERMGR_H
#define _MINESEEPERMGR_H
#include <QObject>
#include <map>
#include <vector>
#include <QTime>
#include "DataDefine.h"


class CMineBlockData;

/*!
 * @class	: CMineSweeperMgr
 * @brief	: 扫雷游戏数据管理类，管理游戏流程及进行数学计算，此类是个单件类
 * @author	: liuk
 * @date	: 2017/02/06 16:21
 */
class CMineSweeperMgr : public QObject
{
	Q_OBJECT
public:
	static CMineSweeperMgr* GetInstance();
	static void ExitInstance();

public:

	/**
	 * @fn		: InitGame
	 * @brief	: 初始化游戏
	 * @access	: public 
	 * @return	: void
	 */
	void InitGame();
	
	/**
	 * @fn		: GetBlock
	 * @brief	: 根据行列号获取方块数据
	 * @access	: public 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: CMineBlockData*
	 */
	CMineBlockData* GetBlock(int nRow, int nCol);

	/**
	 * @fn		: SetRowCounts
	 * @brief	: 设置行数
	 * @access	: public 
	 * @param	: int nRows
	 * @return	: void
	 */
	void SetRowCounts(int nRows);

	/**
	 * @fn		: SetColCounts
	 * @brief	: 设置列数
	 * @access	: public 
	 * @param	: int nCols
	 * @return	: void
	 */
	void SetColCounts(int nCols);

	/**
	 * @fn		: SetMineCount
	 * @brief	:设置地雷数
	 * @access	: public 
	 * @param	: int nMineCnt
	 * @return	: void
	 */
	void SetMineCount(int nMineCnt);

	/**
	 * @fn		: GetAdjoinBlock
	 * @brief	: 获取相邻位置的方块
	 * @access	: public 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @param	: EAdjoinPlace ePlace 相邻位置
	 * @return	: CMineBlockData*
	 */
	
	CMineBlockData* GetAdjoinBlock(int nRow, int nCol, EAdjoinPlace ePlace);
	/**
	* @fn		: GetColumnCount
	* @brief	: 获取行数
	* @access	: protected
	* @return	: int
	*/
	int GetColumnCount() const;

	/**
	* @fn		: GetRowCount
	* @brief	: 获取列数
	* @access	: protected
	* @return	: int
	*/
	int GetRowCount() const;

	/**
	 * @fn		: OpenBlock
	 * @brief	: 打开方块，以及周围的相连合法方块
	 * @access	: public 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: void
	 */
	void OpenBlock(int nRow, int nCol);

	/**
	 * @fn		: UpdateGameProgress
	 * @brief	: 更新游戏进度
	 * @access	: public 
	 * @return	: void
	 */
	void UpdateGameProgress();

	/**
	* @fn		: GameState
	* @brief	: 游戏状态
	* @access	: protected
	* @return	: EGameState
	*/
	EGameState GameState();

	/**
	 * @fn		: GetGameTime
	 * @brief	: 获取游戏的时间，ms
	 * @access	: public 
	 * @return	: QT_NAMESPACE::QTime
	 */
	int GetGameTime();

	/**
	 * @fn		: CalcMarkCount
	 * @brief	: 获取格子周围的标记为地雷的数目
	 * @access	: public 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: int
	 */
	int CalcMarkCount(int nRow, int nCol);

	void ChangeGameModel(EGameModel eGameModel);

	EGameModel GameModel();
protected:
	CMineSweeperMgr();
	~CMineSweeperMgr();

protected:

	/**
	 * @fn		: InitMine
	 * @brief	: 初始化地雷
	 * @access	: protected 
	 * @param	: int nRow 初始化点击的位置，此处不能是地雷
	 * @param	: int nCol
	 * @return	: void
	 */
	void InitMine(int nRow, int nCol);

	/**
	 * @fn		: InitBlock
	 * @brief	: 初始化普通块
	 * @access	: protected 
	 * @return	: void
	 */
	void InitBlock();

	/**
	 * @fn		: CalcMineCnt
	 * @brief	:计算一个方格周围的雷的数量
	 * @access	: protected 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: int
	 */
	int CalcMineCnt(int nRow, int nCol);


	/**
	 * @fn		: Clear
	 * @brief	: 清除数据
	 * @access	: protected 
	 * @return	: void
	 */
	void Clear();

	/**
	* @fn		: InitGame
	* @brief	: 初始化游戏
	* @access	: public
	* @param	: int nRow 初始化点击的方块行号
	* @param	: int nCol 初始化点击的方块列号
	*						,初始化点击的方格不能为地雷
	* @return	: void
	*/
	void StartGame(int nRow, int nCol);

	/**
	 * @fn		: TurnBlock
	 * @brief	:翻开格子
	 * @access	: protected 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: void
	 */
	void TurnBlock(int nRow, int nCol);

	/**
	 * @fn		: LostGame
	 * @brief	: 输掉游戏操作，点翻所有雷
	 * @access	: protected 
	 * @return	: void
	 */
	void LostGame();

	/**
	 * @fn		: NormalOpenBlock
	 * @brief	: 打开方块，常规模式
	 * @access	: protected 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: void
	 */
	void NormalOpenBlock(int nRow, int nCol);

	void WinGame();

	/**
	 * @fn		: QuickOpenBlock
	 * @brief	: 快速打开方块，点击已打开方块，打开其周围所有
	 * @access	: protected 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: void
	 */
	void QuickOpenBlock(int nRow, int nCol);

	/**
	 * @fn		: StrongOpenBlock
	 * @brief	: 强行打开非标记为地雷的格子，是地雷就引爆
	 *			，否则连锁打开周围的所有合适的格子
	 * @access	: protected 
	 * @param	: int nRow
	 * @param	: int nCol
	 * @return	: void
	 */
	void StrongOpenBlock(int nRow, int nCol);
signals:
	void SigGameWin();

	void SigGameLost();

	void SigProgress(double dProgress);
private:
	static CMineSweeperMgr* m_pInstance;

	int m_nRowCnt;
	int m_nColCnt;
	int m_nMineCnt;
	int m_nOverBlock; /// 剩余未打开的方块数
	EGameModel m_eGameModel; // 游戏模式
	// 游戏记时
	QTime m_tmGameClock;

	EGameState m_eGameState; //游戏状况

	std::map<short, CMineBlockData*> m_mapMineMat; // 游戏矩阵数据，key值高8位储存行号，低8位储存列号

	// 未分配的方块，初始化地雷时记录未分配到地雷的方块
	std::vector<short> m_arrNoAllocBlock;
};
#define MineSweerMgrIns (*CMineSweeperMgr::GetInstance())
#endif // _MINESWEEPERMGR_H