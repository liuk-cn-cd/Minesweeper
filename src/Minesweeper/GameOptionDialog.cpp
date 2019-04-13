#include "GameOptionDialog.h"
#include <QButtonGroup>

CGameOptionDialog::CGameOptionDialog(QWidget *parent)
	: QDialog(parent)
	, m_nCol(9)
	, m_nRow(9)
	, m_nMineCnt(9)
{
	ui.setupUi(this);
	QButtonGroup* pBtnGroup = new QButtonGroup;
	pBtnGroup->addButton(ui.radioEasy);
	pBtnGroup->addButton(ui.radioNormal);
	pBtnGroup->addButton(ui.radioDiff);
	pBtnGroup->addButton(ui.radioCus);

	connect(ui.spinBoxRow, SIGNAL(valueChanged(int)), this, SLOT(OnMineChanged(int)));
	connect(ui.spinBoxCol, SIGNAL(valueChanged(int)), this, SLOT(OnMineChanged(int)));
}

CGameOptionDialog::~CGameOptionDialog()
{

}

int CGameOptionDialog::GetRow()
{
	return m_nRow;
}

int CGameOptionDialog::GetCol()
{
	return m_nCol;
}

int CGameOptionDialog::GetMine()
{
	return m_nMineCnt;
}

void CGameOptionDialog::on_ptnOk_clicked()
{
	if (ui.radioEasy->isChecked())
	{
		m_nRow = 9;
		m_nCol = 9;
		m_nMineCnt = 10;
	}
	else if(ui.radioNormal->isChecked())
	{
		m_nRow = 16;
		m_nCol = 16;
		m_nMineCnt = 40;
	}
	else if (ui.radioDiff->isChecked())
	{
		m_nRow = 16;
		m_nCol = 30;
		m_nMineCnt = 99;
	}
	else
	{
		m_nRow = ui.spinBoxRow->value();
		m_nCol = ui.spinBoxCol->value();
		m_nMineCnt = ui.spinBoxMine->value();
	}

	done(QDialog::Accepted);
}

void CGameOptionDialog::on_ptnCancel_clicked()
{
	done(QDialog::Rejected);
}

void CGameOptionDialog::OnMineChanged(int nValue)
{
	m_nRow = ui.spinBoxRow->value();
	m_nCol = ui.spinBoxCol->value();
	ui.spinBoxMine->setRange(9, m_nRow * m_nCol - 2);
	m_nMineCnt = ui.spinBoxMine->value();
}
