/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MineBlock.cpp
 * @brief	:
 * @author	: liuk
 * @date	: 2017/02/06 16:30:37
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "MineBlock.h"
#include <QPainter>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include "MineBlockData.h"
#define BLOCK_WIDTH 40

CMineBlock::CMineBlock(QGraphicsItem *parent)
	: QGraphicsItem(parent)
	, m_pBlockData(nullptr)
{

}

CMineBlock::~CMineBlock()
{

}

void CMineBlock::SetBlockData(CMineBlockData* pBlockData)
{
	m_pBlockData = pBlockData;
	setPos(m_pBlockData->GetColumn() * BLOCK_WIDTH, m_pBlockData->GetRow() * BLOCK_WIDTH);
}

void CMineBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = Q_NULLPTR */)
{
	if (nullptr == m_pBlockData)
	{
		DrawCloseBlock(painter, option);
		return;
	}
	switch (m_pBlockData->GetBlockState())
	{
	case E_STATE_CLOSE:
	{
		DrawCloseBlock(painter, option);
	}
	break;
	case E_STATE_MARK_MINE:
	{
		DrawMarkMine(painter, option);
	}
	break;
	case E_STATE_MARK_UNDE:
	{
		DrawMarkUnde(painter, option);
	}
	break;
	case E_STATE_OPEN:
	{
		DrawOpenBlock(painter, option);
	}
	break;
	default:
	{
		DrawCloseBlock(painter, option);
	}
	break;
	}
}

void CMineBlock::DrawOpenBlock(QPainter *painter, const QStyleOptionGraphicsItem *option)
{
	painter->setPen(Qt::black);
	QRectF rect = boundingRect();
	painter->drawRect(rect);
	QRectF rectFill(rect.left() + 1, rect.top() + 1, rect.width() - 2, rect.height() - 2);


	// 方块周围有多少雷
	int nMineCnt = m_pBlockData->GetAdjoinMineCnt();

	// 如果自己就是雷
	if (m_pBlockData->IsMine())
	{
		painter->setPen(Qt::red);
		painter->fillRect(rectFill, QColor(255, 0, 0));
		QPixmap pixmap(":/Resources/mine.png");
		painter->drawPixmap(rect, pixmap, pixmap.rect());
		return;
	}

	painter->fillRect(rectFill, QColor(255, 255, 255));
	// 如果周围没有雷
	if (m_pBlockData->GetAdjoinMineCnt() == 0)
	{
		return;
	}
	QPen pen(GetTextColorByMineCnt(nMineCnt));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(2);
	painter->setPen(pen);

	QFont font;
	font.setPointSize(18);
	font.setWeight(3);
	font.setBold(true);
	painter->setFont(font);

	QString strNum = QString::number(nMineCnt);
	QTextOption optionText;
	optionText.setAlignment(Qt::AlignCenter);
	painter->drawText(rect, strNum, optionText);
}

void CMineBlock::DrawCloseBlock(QPainter *painter, const QStyleOptionGraphicsItem *option)
{
	painter->setPen(Qt::black);
	QRectF rect = boundingRect();
	QRectF rectFill(rect.left() + 1, rect.top() + 1, rect.width() - 2, rect.height() - 2);
	painter->drawRect(rect);

	painter->fillRect(rectFill, QColor(204, 204, 204));

	QPen pen(Qt::red);
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	painter->setPen(pen);
	QPixmap pixmap(":/Resources/normal.png");
	painter->drawPixmap(rectFill, pixmap, pixmap.rect());
}

void CMineBlock::DrawMarkMine(QPainter *painter, const QStyleOptionGraphicsItem *option)
{
	painter->setPen(Qt::black);
	QRectF rect = boundingRect();
	QRectF rectFill(rect.left() + 1, rect.top() + 1, rect.width() - 2, rect.height() - 2);
	painter->drawRect(rect);
	
	painter->fillRect(rectFill, QColor(204, 204, 204));

	QPen pen(Qt::red);
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	painter->setPen(pen);
	QPixmap pixmap(":/Resources/redflag.png");
	painter->drawPixmap(rectFill, pixmap, pixmap.rect());
}

void CMineBlock::DrawMarkUnde(QPainter *painter, const QStyleOptionGraphicsItem *option)
{
	painter->setPen(Qt::black);
	QRectF rect = boundingRect();
	painter->drawRect(rect);
	QRectF rectFill(rect.left() + 1, rect.top() + 1, rect.width() - 2, rect.height() - 2);
	painter->fillRect(rectFill, QColor(204, 204, 204));

	QPen pen(Qt::red);
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	painter->setPen(pen);

	QFont font;
	font.setPointSize(18);
	font.setWeight(3);
	font.setBold(true);
	painter->setFont(font);

	QString strNum = "?";
	QTextOption optionText;
	optionText.setAlignment(Qt::AlignCenter);
	painter->drawText(rect, strNum, optionText);
}

QColor CMineBlock::GetTextColorByMineCnt(int nMineCnt)
{
	switch (nMineCnt)
	{
	case 1:
	{
		return Qt::green;
	}
	case 2:
	{
		return Qt::blue;
	}
	case 3:
	{
		return Qt::cyan;
	}
	case 4:
	{
		return QColor(0,0,128);
	}
	case 5:
	{
		return Qt::magenta;
	}
	case 6:
	{
		return Qt::red;
	}
	case 7:
	{
		return QColor(128,0,0);
	}
	case 8:
	{
		return Qt::black;
	}
	default:
		break;
	}
	return Qt::white;
}

void CMineBlock::OnMouseClicked()
{
	if(NULL != m_pBlockData)
	{
//		if (m_pBlockData->GetBlockState() != E_STATE_OPEN)
		{
			emit SigBlockOpen(m_pBlockData->GetRow(), m_pBlockData->GetColumn());
		}
	}
}

QRectF CMineBlock::boundingRect() const
{
	return QRectF(0, 0, 40, 40);
}

void CMineBlock::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_tmClick.restart();
	}
	else if (event->button() == Qt::RightButton)
	{
		if (m_pBlockData->GetBlockState() == E_STATE_OPEN)
		{
			return;
		}
		else if (m_pBlockData->GetBlockState() == E_STATE_CLOSE)
		{
			m_pBlockData->SetBlockState(E_STATE_MARK_MINE);
		}
		else if (m_pBlockData->GetBlockState() == E_STATE_MARK_MINE)
		{
			m_pBlockData->SetBlockState(E_STATE_MARK_UNDE);
		}
		else if (m_pBlockData->GetBlockState() == E_STATE_MARK_UNDE)
		{
			m_pBlockData->SetBlockState(E_STATE_CLOSE);
		}
		update();
	}
}

void CMineBlock::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && m_tmClick.elapsed() < 200)
	{
		OnMouseClicked();
	}
	
}
