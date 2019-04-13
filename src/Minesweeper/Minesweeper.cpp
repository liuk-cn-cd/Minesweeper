/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: Minesweeper.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/02/06 16:31:14
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */

#include "Minesweeper.h"
#include "MineScene.h"
#include "MineSweeperMgr.h"
#include "GameOptionDialog.h"

Minesweeper::Minesweeper(QWidget *parent)
	: QMainWindow(parent)
	, m_nTimerId(-1)
{
	ui.setupUi(this);
	m_pScene = new CMineScene(ui.graphicsView);
	ui.graphicsView->setScene(m_pScene);
	this->setFixedWidth(10 * 40 + 191);
	this->setFixedHeight(10 * 40 + 78);

	connect(CMineSweeperMgr::GetInstance()
		, SIGNAL(SigProgress(double)), this
		, SLOT(SlotProgress(double)));

	connect(CMineSweeperMgr::GetInstance(), SIGNAL(SigGameWin())
		, this, SLOT(SlotGameWin()));

	connect(CMineSweeperMgr::GetInstance(), SIGNAL(SigGameLost())
		, this, SLOT(SlotGameOver()));

	MineSweerMgrIns.SetRowCounts(10);
	MineSweerMgrIns.SetColCounts(10);
	MineSweerMgrIns.SetMineCount(9);
	MineSweerMgrIns.InitGame();
	m_pScene->RestartGame();
}

Minesweeper::~Minesweeper()
{

}

void Minesweeper::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == m_nTimerId)
	{
		int nMs = MineSweerMgrIns.GetGameTime();
		QString strTime = QString::number(nMs / 1000.0, 'f', 3);
		ui.lcdTime->display(strTime);

		if(MineSweerMgrIns.GameState() != E_GAME_IN)
		{
			killTimer(m_nTimerId);
			m_nTimerId = -1;
		}
	}
}

void Minesweeper::on_actionOption_triggered()
{
	CGameOptionDialog dlg;
	if (dlg.exec() == QDialog::Accepted)
	{
		MineSweerMgrIns.SetColCounts(dlg.GetCol());
		MineSweerMgrIns.SetRowCounts(dlg.GetRow());
		MineSweerMgrIns.SetMineCount(dlg.GetMine());
		m_pScene->setSceneRect(0, 0, dlg.GetCol() * 40, dlg.GetRow() * 40);
		this->setFixedWidth(dlg.GetCol() * 40 + 191);
		this->setFixedHeight(dlg.GetRow() * 40 + 78);
		MineSweerMgrIns.InitGame();
		m_pScene->RestartGame();
	}
}

void Minesweeper::on_ptnNewGame_clicked()
{
	ui.labelGameState->setText(QStringLiteral("欢迎！！！"));
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::blue);
	ui.labelGameState->setPalette(palette);
	MineSweerMgrIns.InitGame();
	m_pScene->RestartGame();
	ui.ptnNewGame->setIcon(QIcon(":/Resources/angry.png"));
}

void Minesweeper::on_ptnModel_toggled(bool bCheck)
{
	if (bCheck)
	{
		ui.ptnModel->setIcon(QIcon(":/Resources/blackflag.png"));
		MineSweerMgrIns.ChangeGameModel(E_GAME_FLAG_MODEL);
	}
	else
	{
		ui.ptnModel->setIcon(QIcon(":/Resources/Spade.png"));
		MineSweerMgrIns.ChangeGameModel(E_GAME_TURN_MODEL);
	}
}

void Minesweeper::SlotGameOver()
{

	ui.labelGameState->setText(QStringLiteral("失败"));
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::red);
	ui.labelGameState->setPalette(palette);
	ui.ptnNewGame->setIcon(QIcon(":/Resources/anger.png"));
}

void Minesweeper::SlotGameWin()
{
	ui.labelGameState->setText(QStringLiteral("恭喜！！！"));
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::green);
	ui.labelGameState->setPalette(palette);
	ui.ptnNewGame->setIcon(QIcon(":/Resources/smiley.png"));
}

void Minesweeper::SlotProgress(double dProgress)
{
	if (m_nTimerId == -1)
	{
		m_nTimerId = startTimer(10);
		ui.labelGameState->setText(QStringLiteral("游戏中"));
		QPalette palette;
		palette.setColor(QPalette::WindowText, Qt::cyan);
		ui.labelGameState->setPalette(palette);
	}
	QString strNum = QString::number(dProgress, 'f', 1);
	ui.lcdProgress->display(strNum);
}
