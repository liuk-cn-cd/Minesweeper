/********************************************************************************
** Form generated from reading UI file 'Minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MinesweeperClass
{
public:
    QAction *actionOption;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *toolBar;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptnNewGame;
    QPushButton *ptnModel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *infoBar;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdTime;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdProgress;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLCDNumber *lcdMineCnt;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelGameState;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MinesweeperClass)
    {
        if (MinesweeperClass->objectName().isEmpty())
            MinesweeperClass->setObjectName(QStringLiteral("MinesweeperClass"));
        MinesweeperClass->resize(707, 566);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/mine.png"), QSize(), QIcon::Normal, QIcon::Off);
        MinesweeperClass->setWindowIcon(icon);
        actionOption = new QAction(MinesweeperClass);
        actionOption->setObjectName(QStringLiteral("actionOption"));
        centralWidget = new QWidget(MinesweeperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        toolBar = new QWidget(centralWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        horizontalLayout_5 = new QHBoxLayout(toolBar);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(301, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        ptnNewGame = new QPushButton(toolBar);
        ptnNewGame->setObjectName(QStringLiteral("ptnNewGame"));
        ptnNewGame->setMinimumSize(QSize(40, 40));
        ptnNewGame->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/angry.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptnNewGame->setIcon(icon1);
        ptnNewGame->setIconSize(QSize(40, 40));

        horizontalLayout_5->addWidget(ptnNewGame);

        ptnModel = new QPushButton(toolBar);
        ptnModel->setObjectName(QStringLiteral("ptnModel"));
        ptnModel->setMinimumSize(QSize(40, 40));
        ptnModel->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Spade.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptnModel->setIcon(icon2);
        ptnModel->setIconSize(QSize(40, 40));
        ptnModel->setCheckable(true);
        ptnModel->setChecked(false);

        horizontalLayout_5->addWidget(ptnModel);

        horizontalSpacer_2 = new QSpacerItem(301, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(toolBar);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        infoBar = new QWidget(centralWidget);
        infoBar->setObjectName(QStringLiteral("infoBar"));
        verticalLayout = new QVBoxLayout(infoBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(infoBar);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(45, 0));
        label->setMaximumSize(QSize(45, 16777215));

        horizontalLayout->addWidget(label);

        lcdTime = new QLCDNumber(infoBar);
        lcdTime->setObjectName(QStringLiteral("lcdTime"));
        lcdTime->setMinimumSize(QSize(80, 0));
        lcdTime->setFrameShadow(QFrame::Sunken);
        lcdTime->setLineWidth(1);
        lcdTime->setDigitCount(8);
        lcdTime->setMode(QLCDNumber::Dec);
        lcdTime->setSegmentStyle(QLCDNumber::Flat);
        lcdTime->setProperty("value", QVariant(0));

        horizontalLayout->addWidget(lcdTime);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(infoBar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(45, 0));
        label_2->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lcdProgress = new QLCDNumber(infoBar);
        lcdProgress->setObjectName(QStringLiteral("lcdProgress"));
        lcdProgress->setMinimumSize(QSize(62, 0));
        lcdProgress->setFrameShape(QFrame::Box);
        lcdProgress->setFrameShadow(QFrame::Sunken);
        lcdProgress->setLineWidth(1);
        lcdProgress->setDigitCount(5);
        lcdProgress->setSegmentStyle(QLCDNumber::Flat);
        lcdProgress->setProperty("value", QVariant(100));

        horizontalLayout_2->addWidget(lcdProgress);

        label_3 = new QLabel(infoBar);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(infoBar);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(45, 0));
        label_4->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_3->addWidget(label_4);

        lcdMineCnt = new QLCDNumber(infoBar);
        lcdMineCnt->setObjectName(QStringLiteral("lcdMineCnt"));
        lcdMineCnt->setMinimumSize(QSize(80, 0));
        lcdMineCnt->setFrameShadow(QFrame::Sunken);
        lcdMineCnt->setLineWidth(1);
        lcdMineCnt->setDigitCount(8);
        lcdMineCnt->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdMineCnt);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        labelGameState = new QLabel(infoBar);
        labelGameState->setObjectName(QStringLiteral("labelGameState"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelGameState->setFont(font);

        verticalLayout->addWidget(labelGameState);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(infoBar);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout_4->addWidget(graphicsView);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MinesweeperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MinesweeperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 30));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MinesweeperClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOption);

        retranslateUi(MinesweeperClass);

        QMetaObject::connectSlotsByName(MinesweeperClass);
    } // setupUi

    void retranslateUi(QMainWindow *MinesweeperClass)
    {
        MinesweeperClass->setWindowTitle(QApplication::translate("MinesweeperClass", "\346\211\253\351\233\267", 0));
        actionOption->setText(QApplication::translate("MinesweeperClass", "\346\270\270\346\210\217\350\256\276\347\275\256", 0));
        ptnNewGame->setText(QString());
        ptnModel->setText(QString());
        label->setText(QApplication::translate("MinesweeperClass", "\346\227\266\351\227\264\357\274\232", 0));
        label_2->setText(QApplication::translate("MinesweeperClass", "\350\277\233\345\272\246\357\274\232", 0));
        label_3->setText(QApplication::translate("MinesweeperClass", "%", 0));
        label_4->setText(QApplication::translate("MinesweeperClass", "\345\234\260\351\233\267\357\274\232", 0));
        labelGameState->setText(QApplication::translate("MinesweeperClass", "\346\254\242\350\277\216\357\274\201\357\274\201\357\274\201\357\274\201", 0));
        menu->setTitle(QApplication::translate("MinesweeperClass", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MinesweeperClass: public Ui_MinesweeperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
