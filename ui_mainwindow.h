/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionHelp;
    QWidget *centralWidget;
    QLabel *Display;
    QPushButton *Backspace;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *one;
    QPushButton *two;
    QPushButton *decimal;
    QPushButton *divide;
    QPushButton *zero;
    QPushButton *negative;
    QPushButton *six;
    QPushButton *subtract;
    QPushButton *plus;
    QPushButton *four;
    QPushButton *leftPar;
    QPushButton *seven;
    QPushButton *five;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *rightPar;
    QPushButton *power;
    QPushButton *three;
    QPushButton *multiply;
    QPushButton *memoryErase;
    QPushButton *memoryclear;
    QPushButton *split;
    QPushButton *clear;
    QPushButton *divider;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *MemoryK;
    QPushButton *MemoryR;
    QPushButton *MemoryB;
    QPushButton *MemoryH;
    QPushButton *MemoryC;
    QPushButton *MemoryS;
    QPushButton *MemoryT;
    QPushButton *MemoryL;
    QPushButton *MemoryM;
    QPushButton *MemoryD;
    QPushButton *MemoryA;
    QPushButton *MemoryF;
    QPushButton *MemoryP;
    QPushButton *MemoryN;
    QPushButton *MemoryG;
    QPushButton *MemoryJ;
    QPushButton *MemoryQ;
    QPushButton *MemoryE;
    QPushButton *MemoryI;
    QPushButton *MemoryO;
    QPushButton *MemoryU;
    QPushButton *MemoryV;
    QPushButton *MemoryW;
    QPushButton *MemoryX;
    QPushButton *MemoryY;
    QPushButton *MemoryZ;
    QPushButton *equals;
    QPushButton *Enter;
    QLabel *RPN;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(568, 424);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHelp->setCheckable(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Display = new QLabel(centralWidget);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setGeometry(QRect(40, 10, 380, 40));
        QFont font;
        font.setPointSize(14);
        Display->setFont(font);
        Display->setAutoFillBackground(false);
        Display->setStyleSheet(QStringLiteral("background-color: white"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Backspace = new QPushButton(centralWidget);
        Backspace->setObjectName(QStringLiteral("Backspace"));
        Backspace->setGeometry(QRect(430, 20, 113, 32));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 130, 511, 202));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setChildrenCollapsible(false);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        one = new QPushButton(layoutWidget);
        one->setObjectName(QStringLiteral("one"));

        gridLayout->addWidget(one, 4, 0, 1, 1);

        two = new QPushButton(layoutWidget);
        two->setObjectName(QStringLiteral("two"));

        gridLayout->addWidget(two, 4, 1, 1, 1);

        decimal = new QPushButton(layoutWidget);
        decimal->setObjectName(QStringLiteral("decimal"));

        gridLayout->addWidget(decimal, 5, 0, 1, 1);

        divide = new QPushButton(layoutWidget);
        divide->setObjectName(QStringLiteral("divide"));

        gridLayout->addWidget(divide, 5, 3, 1, 1);

        zero = new QPushButton(layoutWidget);
        zero->setObjectName(QStringLiteral("zero"));

        gridLayout->addWidget(zero, 5, 1, 1, 1);

        negative = new QPushButton(layoutWidget);
        negative->setObjectName(QStringLiteral("negative"));

        gridLayout->addWidget(negative, 5, 2, 1, 1);

        six = new QPushButton(layoutWidget);
        six->setObjectName(QStringLiteral("six"));

        gridLayout->addWidget(six, 3, 2, 1, 1);

        subtract = new QPushButton(layoutWidget);
        subtract->setObjectName(QStringLiteral("subtract"));

        gridLayout->addWidget(subtract, 3, 3, 1, 1);

        plus = new QPushButton(layoutWidget);
        plus->setObjectName(QStringLiteral("plus"));

        gridLayout->addWidget(plus, 2, 3, 1, 1);

        four = new QPushButton(layoutWidget);
        four->setObjectName(QStringLiteral("four"));

        gridLayout->addWidget(four, 3, 0, 1, 1);

        leftPar = new QPushButton(layoutWidget);
        leftPar->setObjectName(QStringLiteral("leftPar"));

        gridLayout->addWidget(leftPar, 1, 1, 1, 1);

        seven = new QPushButton(layoutWidget);
        seven->setObjectName(QStringLiteral("seven"));

        gridLayout->addWidget(seven, 2, 0, 1, 1);

        five = new QPushButton(layoutWidget);
        five->setObjectName(QStringLiteral("five"));

        gridLayout->addWidget(five, 3, 1, 1, 1);

        eight = new QPushButton(layoutWidget);
        eight->setObjectName(QStringLiteral("eight"));

        gridLayout->addWidget(eight, 2, 1, 1, 1);

        nine = new QPushButton(layoutWidget);
        nine->setObjectName(QStringLiteral("nine"));

        gridLayout->addWidget(nine, 2, 2, 1, 1);

        rightPar = new QPushButton(layoutWidget);
        rightPar->setObjectName(QStringLiteral("rightPar"));

        gridLayout->addWidget(rightPar, 1, 2, 1, 1);

        power = new QPushButton(layoutWidget);
        power->setObjectName(QStringLiteral("power"));

        gridLayout->addWidget(power, 1, 0, 1, 1);

        three = new QPushButton(layoutWidget);
        three->setObjectName(QStringLiteral("three"));

        gridLayout->addWidget(three, 4, 2, 1, 1);

        multiply = new QPushButton(layoutWidget);
        multiply->setObjectName(QStringLiteral("multiply"));

        gridLayout->addWidget(multiply, 4, 3, 1, 1);

        memoryErase = new QPushButton(layoutWidget);
        memoryErase->setObjectName(QStringLiteral("memoryErase"));

        gridLayout->addWidget(memoryErase, 0, 0, 1, 1);

        memoryclear = new QPushButton(layoutWidget);
        memoryclear->setObjectName(QStringLiteral("memoryclear"));

        gridLayout->addWidget(memoryclear, 0, 1, 1, 1);

        split = new QPushButton(layoutWidget);
        split->setObjectName(QStringLiteral("split"));

        gridLayout->addWidget(split, 1, 3, 1, 1);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout->addWidget(clear, 0, 2, 1, 1);

        divider = new QPushButton(layoutWidget);
        divider->setObjectName(QStringLiteral("divider"));

        gridLayout->addWidget(divider, 0, 3, 1, 1);

        splitter->addWidget(layoutWidget);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        MemoryK = new QPushButton(gridLayoutWidget);
        MemoryK->setObjectName(QStringLiteral("MemoryK"));

        gridLayout_2->addWidget(MemoryK, 2, 2, 1, 1);

        MemoryR = new QPushButton(gridLayoutWidget);
        MemoryR->setObjectName(QStringLiteral("MemoryR"));

        gridLayout_2->addWidget(MemoryR, 4, 1, 1, 1);

        MemoryB = new QPushButton(gridLayoutWidget);
        MemoryB->setObjectName(QStringLiteral("MemoryB"));

        gridLayout_2->addWidget(MemoryB, 0, 1, 1, 1);

        MemoryH = new QPushButton(gridLayoutWidget);
        MemoryH->setObjectName(QStringLiteral("MemoryH"));

        gridLayout_2->addWidget(MemoryH, 1, 3, 1, 1);

        MemoryC = new QPushButton(gridLayoutWidget);
        MemoryC->setObjectName(QStringLiteral("MemoryC"));

        gridLayout_2->addWidget(MemoryC, 0, 2, 1, 1);

        MemoryS = new QPushButton(gridLayoutWidget);
        MemoryS->setObjectName(QStringLiteral("MemoryS"));

        gridLayout_2->addWidget(MemoryS, 4, 2, 1, 1);

        MemoryT = new QPushButton(gridLayoutWidget);
        MemoryT->setObjectName(QStringLiteral("MemoryT"));

        gridLayout_2->addWidget(MemoryT, 4, 3, 1, 1);

        MemoryL = new QPushButton(gridLayoutWidget);
        MemoryL->setObjectName(QStringLiteral("MemoryL"));

        gridLayout_2->addWidget(MemoryL, 2, 3, 1, 1);

        MemoryM = new QPushButton(gridLayoutWidget);
        MemoryM->setObjectName(QStringLiteral("MemoryM"));

        gridLayout_2->addWidget(MemoryM, 3, 0, 1, 1);

        MemoryD = new QPushButton(gridLayoutWidget);
        MemoryD->setObjectName(QStringLiteral("MemoryD"));

        gridLayout_2->addWidget(MemoryD, 0, 3, 1, 1);

        MemoryA = new QPushButton(gridLayoutWidget);
        MemoryA->setObjectName(QStringLiteral("MemoryA"));

        gridLayout_2->addWidget(MemoryA, 0, 0, 1, 1);

        MemoryF = new QPushButton(gridLayoutWidget);
        MemoryF->setObjectName(QStringLiteral("MemoryF"));

        gridLayout_2->addWidget(MemoryF, 1, 1, 1, 1);

        MemoryP = new QPushButton(gridLayoutWidget);
        MemoryP->setObjectName(QStringLiteral("MemoryP"));

        gridLayout_2->addWidget(MemoryP, 3, 3, 1, 1);

        MemoryN = new QPushButton(gridLayoutWidget);
        MemoryN->setObjectName(QStringLiteral("MemoryN"));

        gridLayout_2->addWidget(MemoryN, 3, 1, 1, 1);

        MemoryG = new QPushButton(gridLayoutWidget);
        MemoryG->setObjectName(QStringLiteral("MemoryG"));

        gridLayout_2->addWidget(MemoryG, 1, 2, 1, 1);

        MemoryJ = new QPushButton(gridLayoutWidget);
        MemoryJ->setObjectName(QStringLiteral("MemoryJ"));

        gridLayout_2->addWidget(MemoryJ, 2, 1, 1, 1);

        MemoryQ = new QPushButton(gridLayoutWidget);
        MemoryQ->setObjectName(QStringLiteral("MemoryQ"));

        gridLayout_2->addWidget(MemoryQ, 4, 0, 1, 1);

        MemoryE = new QPushButton(gridLayoutWidget);
        MemoryE->setObjectName(QStringLiteral("MemoryE"));

        gridLayout_2->addWidget(MemoryE, 1, 0, 1, 1);

        MemoryI = new QPushButton(gridLayoutWidget);
        MemoryI->setObjectName(QStringLiteral("MemoryI"));

        gridLayout_2->addWidget(MemoryI, 2, 0, 1, 1);

        MemoryO = new QPushButton(gridLayoutWidget);
        MemoryO->setObjectName(QStringLiteral("MemoryO"));

        gridLayout_2->addWidget(MemoryO, 3, 2, 1, 1);

        MemoryU = new QPushButton(gridLayoutWidget);
        MemoryU->setObjectName(QStringLiteral("MemoryU"));

        gridLayout_2->addWidget(MemoryU, 5, 0, 1, 1);

        MemoryV = new QPushButton(gridLayoutWidget);
        MemoryV->setObjectName(QStringLiteral("MemoryV"));

        gridLayout_2->addWidget(MemoryV, 5, 1, 1, 1);

        MemoryW = new QPushButton(gridLayoutWidget);
        MemoryW->setObjectName(QStringLiteral("MemoryW"));

        gridLayout_2->addWidget(MemoryW, 5, 2, 1, 1);

        MemoryX = new QPushButton(gridLayoutWidget);
        MemoryX->setObjectName(QStringLiteral("MemoryX"));

        gridLayout_2->addWidget(MemoryX, 5, 3, 1, 1);

        MemoryY = new QPushButton(gridLayoutWidget);
        MemoryY->setObjectName(QStringLiteral("MemoryY"));

        gridLayout_2->addWidget(MemoryY, 6, 0, 1, 1);

        MemoryZ = new QPushButton(gridLayoutWidget);
        MemoryZ->setObjectName(QStringLiteral("MemoryZ"));

        gridLayout_2->addWidget(MemoryZ, 6, 1, 1, 1);

        equals = new QPushButton(gridLayoutWidget);
        equals->setObjectName(QStringLiteral("equals"));

        gridLayout_2->addWidget(equals, 6, 2, 1, 1);

        Enter = new QPushButton(gridLayoutWidget);
        Enter->setObjectName(QStringLiteral("Enter"));

        gridLayout_2->addWidget(Enter, 6, 3, 1, 1);

        splitter->addWidget(gridLayoutWidget);
        RPN = new QLabel(centralWidget);
        RPN->setObjectName(QStringLiteral("RPN"));
        RPN->setGeometry(QRect(40, 70, 380, 40));
        RPN->setStyleSheet(QStringLiteral("background-color: white"));
        RPN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 568, 26));
        menuBar->setDefaultUp(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        Display->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Backspace->setText(QApplication::translate("MainWindow", "Bksp", 0));
        one->setText(QApplication::translate("MainWindow", "1", 0));
        two->setText(QApplication::translate("MainWindow", "2", 0));
        decimal->setText(QApplication::translate("MainWindow", ".", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        zero->setText(QApplication::translate("MainWindow", "0", 0));
        negative->setText(QApplication::translate("MainWindow", "(-)", 0));
        six->setText(QApplication::translate("MainWindow", "6", 0));
        subtract->setText(QApplication::translate("MainWindow", "-", 0));
        plus->setText(QApplication::translate("MainWindow", "+", 0));
        four->setText(QApplication::translate("MainWindow", "4", 0));
        leftPar->setText(QApplication::translate("MainWindow", "(", 0));
        seven->setText(QApplication::translate("MainWindow", "7", 0));
        five->setText(QApplication::translate("MainWindow", "5", 0));
        eight->setText(QApplication::translate("MainWindow", "8", 0));
        nine->setText(QApplication::translate("MainWindow", "9", 0));
        rightPar->setText(QApplication::translate("MainWindow", ")", 0));
        power->setText(QApplication::translate("MainWindow", "y\342\201\277", 0));
        three->setText(QApplication::translate("MainWindow", "3", 0));
        multiply->setText(QApplication::translate("MainWindow", "x", 0));
        memoryErase->setText(QApplication::translate("MainWindow", "M-", 0));
        memoryclear->setText(QApplication::translate("MainWindow", "MC", 0));
        split->setText(QApplication::translate("MainWindow", "_", 0));
        clear->setText(QApplication::translate("MainWindow", "C", 0));
        divider->setText(QApplication::translate("MainWindow", "A/B", 0));
        MemoryK->setText(QApplication::translate("MainWindow", "K", 0));
        MemoryR->setText(QApplication::translate("MainWindow", "R", 0));
        MemoryB->setText(QApplication::translate("MainWindow", "B", 0));
        MemoryH->setText(QApplication::translate("MainWindow", "H", 0));
        MemoryC->setText(QApplication::translate("MainWindow", "C", 0));
        MemoryS->setText(QApplication::translate("MainWindow", "S", 0));
        MemoryT->setText(QApplication::translate("MainWindow", "T", 0));
        MemoryL->setText(QApplication::translate("MainWindow", "L", 0));
        MemoryM->setText(QApplication::translate("MainWindow", "M", 0));
        MemoryD->setText(QApplication::translate("MainWindow", "D", 0));
        MemoryA->setText(QApplication::translate("MainWindow", "A", 0));
        MemoryF->setText(QApplication::translate("MainWindow", "F", 0));
        MemoryP->setText(QApplication::translate("MainWindow", "P", 0));
        MemoryN->setText(QApplication::translate("MainWindow", "N", 0));
        MemoryG->setText(QApplication::translate("MainWindow", "G", 0));
        MemoryJ->setText(QApplication::translate("MainWindow", "J", 0));
        MemoryQ->setText(QApplication::translate("MainWindow", "Q", 0));
        MemoryE->setText(QApplication::translate("MainWindow", "E", 0));
        MemoryI->setText(QApplication::translate("MainWindow", "I", 0));
        MemoryO->setText(QApplication::translate("MainWindow", "O", 0));
        MemoryU->setText(QApplication::translate("MainWindow", "U", 0));
        MemoryV->setText(QApplication::translate("MainWindow", "V", 0));
        MemoryW->setText(QApplication::translate("MainWindow", "W", 0));
        MemoryX->setText(QApplication::translate("MainWindow", "X", 0));
        MemoryY->setText(QApplication::translate("MainWindow", "Y", 0));
        MemoryZ->setText(QApplication::translate("MainWindow", "Z", 0));
        equals->setText(QApplication::translate("MainWindow", "=", 0));
        Enter->setText(QApplication::translate("MainWindow", "Ent", 0));
        RPN->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
