/********************************************************************************
** Form generated from reading UI file 'GameOptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOPTIONDIALOG_H
#define UI_GAMEOPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CGameOptionDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *radioEasy;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QRadioButton *radioNormal;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QRadioButton *radioDiff;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioCus;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QSpinBox *spinBoxRow;
    QLabel *label_8;
    QSpinBox *spinBoxCol;
    QLabel *label_9;
    QSpinBox *spinBoxMine;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptnOk;
    QPushButton *ptnCancel;

    void setupUi(QDialog *CGameOptionDialog)
    {
        if (CGameOptionDialog->objectName().isEmpty())
            CGameOptionDialog->setObjectName(QStringLiteral("CGameOptionDialog"));
        CGameOptionDialog->resize(467, 281);
        verticalLayout_6 = new QVBoxLayout(CGameOptionDialog);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(CGameOptionDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        radioEasy = new QRadioButton(groupBox);
        radioEasy->setObjectName(QStringLiteral("radioEasy"));
        radioEasy->setChecked(true);

        verticalLayout->addWidget(radioEasy);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        radioNormal = new QRadioButton(groupBox);
        radioNormal->setObjectName(QStringLiteral("radioNormal"));

        verticalLayout_2->addWidget(radioNormal);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        radioDiff = new QRadioButton(groupBox);
        radioDiff->setObjectName(QStringLiteral("radioDiff"));

        verticalLayout_3->addWidget(radioDiff);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addWidget(groupBox);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioCus = new QRadioButton(CGameOptionDialog);
        radioCus->setObjectName(QStringLiteral("radioCus"));

        verticalLayout_5->addWidget(radioCus);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(20);
        label_7 = new QLabel(CGameOptionDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        spinBoxRow = new QSpinBox(CGameOptionDialog);
        spinBoxRow->setObjectName(QStringLiteral("spinBoxRow"));
        spinBoxRow->setMinimum(9);
        spinBoxRow->setMaximum(24);

        gridLayout->addWidget(spinBoxRow, 0, 1, 1, 1);

        label_8 = new QLabel(CGameOptionDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        spinBoxCol = new QSpinBox(CGameOptionDialog);
        spinBoxCol->setObjectName(QStringLiteral("spinBoxCol"));
        spinBoxCol->setMinimum(9);
        spinBoxCol->setMaximum(30);

        gridLayout->addWidget(spinBoxCol, 1, 1, 1, 1);

        label_9 = new QLabel(CGameOptionDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        spinBoxMine = new QSpinBox(CGameOptionDialog);
        spinBoxMine->setObjectName(QStringLiteral("spinBoxMine"));
        spinBoxMine->setMinimum(9);
        spinBoxMine->setMaximum(900);

        gridLayout->addWidget(spinBoxMine, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ptnOk = new QPushButton(CGameOptionDialog);
        ptnOk->setObjectName(QStringLiteral("ptnOk"));

        horizontalLayout->addWidget(ptnOk);

        ptnCancel = new QPushButton(CGameOptionDialog);
        ptnCancel->setObjectName(QStringLiteral("ptnCancel"));

        horizontalLayout->addWidget(ptnCancel);


        verticalLayout_6->addLayout(horizontalLayout);


        retranslateUi(CGameOptionDialog);

        QMetaObject::connectSlotsByName(CGameOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *CGameOptionDialog)
    {
        CGameOptionDialog->setWindowTitle(QApplication::translate("CGameOptionDialog", "\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("CGameOptionDialog", "\351\232\276\345\272\246", 0));
        label->setText(QApplication::translate("CGameOptionDialog", "   \345\210\235\347\272\247", 0));
        radioEasy->setText(QApplication::translate("CGameOptionDialog", "10\344\270\252\351\233\267", 0));
        label_2->setText(QApplication::translate("CGameOptionDialog", "   9 x 9\345\271\263\351\223\272\347\275\221\346\240\274", 0));
        label_3->setText(QApplication::translate("CGameOptionDialog", "   \344\270\255\347\272\247", 0));
        radioNormal->setText(QApplication::translate("CGameOptionDialog", "40\344\270\252\351\233\267", 0));
        label_4->setText(QApplication::translate("CGameOptionDialog", "   16 x 16\345\271\263\351\223\272\347\275\221\346\240\274", 0));
        label_5->setText(QApplication::translate("CGameOptionDialog", "   \351\253\230\347\272\247", 0));
        radioDiff->setText(QApplication::translate("CGameOptionDialog", "99\344\270\252\351\233\267", 0));
        label_6->setText(QApplication::translate("CGameOptionDialog", "   16 x 30\345\271\263\351\223\272\347\275\221\346\240\274", 0));
        radioCus->setText(QApplication::translate("CGameOptionDialog", "\350\207\252\345\256\232\344\271\211", 0));
        label_7->setText(QApplication::translate("CGameOptionDialog", "\351\253\230\345\272\246(9-24):", 0));
        label_8->setText(QApplication::translate("CGameOptionDialog", "\345\256\275\345\272\246(9-30):", 0));
        label_9->setText(QApplication::translate("CGameOptionDialog", "\345\234\260\351\233\267:", 0));
        ptnOk->setText(QApplication::translate("CGameOptionDialog", "\347\241\256\345\256\232", 0));
        ptnCancel->setText(QApplication::translate("CGameOptionDialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class CGameOptionDialog: public Ui_CGameOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOPTIONDIALOG_H
