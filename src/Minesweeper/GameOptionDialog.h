#ifndef GAMEOPTIONDIALOG_H
#define GAMEOPTIONDIALOG_H

#include <QDialog>
#include "ui_GameOptionDialog.h"

class CGameOptionDialog : public QDialog
{
	Q_OBJECT

public:
	CGameOptionDialog(QWidget *parent = 0);
	~CGameOptionDialog();

	int GetRow();

	int GetCol();

	int GetMine();
protected slots:
	void on_ptnOk_clicked();
	
	void on_ptnCancel_clicked();

	/**
	 * @fn		: OnMineChanged
	 * @brief	: 行列数改变
	 * @access	: protected 
	 * @param	: int nValue
	 * @return	: void
	 */
	void OnMineChanged(int nValue);
private:
	Ui::CGameOptionDialog ui;

	int m_nRow;

	int m_nCol;

	int m_nMineCnt;
};

#endif // GAMEOPTIONDIALOG_H
