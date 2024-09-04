/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mytableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionAdd;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionSearch;
    QAction *actionAbout_Qt;
    QAction *actionAbout_App;
    QAction *actionReset;
    QAction *actionNew_Window;
    QAction *actionPrint;
    QAction *actionChart;
    QAction *actionSearch_2;
    QAction *actionEnglish;
    QAction *actionRussian;
    QAction *actionRussian_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *comboBox_Column;
    QLabel *label_Column;
    QLabel *label_Syntax;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QGridLayout *gridLayout_2;
    MyTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_DragNDrop;
    QComboBox *comboBox_MimeType;
    QPushButton *pushButton_Reset;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuLanguage;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setWindowTitle(QString::fromUtf8("MainWindow"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName("actionAdd");
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName("actionEdit");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName("actionSearch");
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName("actionAbout_Qt");
        actionAbout_App = new QAction(MainWindow);
        actionAbout_App->setObjectName("actionAbout_App");
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName("actionReset");
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName("actionNew_Window");
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName("actionPrint");
        actionChart = new QAction(MainWindow);
        actionChart->setObjectName("actionChart");
        actionSearch_2 = new QAction(MainWindow);
        actionSearch_2->setObjectName("actionSearch_2");
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName("actionEnglish");
        actionRussian = new QAction(MainWindow);
        actionRussian->setObjectName("actionRussian");
        actionRussian_2 = new QAction(MainWindow);
        actionRussian_2->setObjectName("actionRussian_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        comboBox_Column = new QComboBox(centralwidget);
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->addItem(QString());
        comboBox_Column->setObjectName("comboBox_Column");

        gridLayout->addWidget(comboBox_Column, 2, 3, 1, 1);

        label_Column = new QLabel(centralwidget);
        label_Column->setObjectName("label_Column");

        gridLayout->addWidget(label_Column, 0, 3, 1, 1);

        label_Syntax = new QLabel(centralwidget);
        label_Syntax->setObjectName("label_Syntax");

        gridLayout->addWidget(label_Syntax, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");

        verticalLayout->addLayout(gridLayout_2);

        tableView = new MyTableView(centralwidget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_DragNDrop = new QLabel(centralwidget);
        label_DragNDrop->setObjectName("label_DragNDrop");

        horizontalLayout->addWidget(label_DragNDrop);

        comboBox_MimeType = new QComboBox(centralwidget);
        comboBox_MimeType->addItem(QString());
        comboBox_MimeType->addItem(QString());
        comboBox_MimeType->addItem(QString());
        comboBox_MimeType->setObjectName("comboBox_MimeType");

        horizontalLayout->addWidget(comboBox_MimeType);

        pushButton_Reset = new QPushButton(centralwidget);
        pushButton_Reset->setObjectName("pushButton_Reset");

        horizontalLayout->addWidget(pushButton_Reset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuEdit->setEnabled(false);
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName("menuLanguage");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionChart);
        menuFile->addAction(actionSearch_2);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionAdd);
        menuEdit->addAction(actionEdit);
        menuEdit->addAction(actionDelete);
        menuAbout->addAction(actionAbout_Qt);
        menuAbout->addAction(actionAbout_App);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionNew->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionAbout_App->setText(QCoreApplication::translate("MainWindow", "About App", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("MainWindow", "New Window", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        actionChart->setText(QCoreApplication::translate("MainWindow", "Chart", nullptr));
        actionSearch_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "Deutsch", nullptr));
        actionRussian->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionRussian_2->setText(QCoreApplication::translate("MainWindow", "Russian", nullptr));
        comboBox_Column->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox_Column->setItemText(1, QCoreApplication::translate("MainWindow", "Name", nullptr));
        comboBox_Column->setItemText(2, QCoreApplication::translate("MainWindow", "Address", nullptr));
        comboBox_Column->setItemText(3, QCoreApplication::translate("MainWindow", "Maxweight", nullptr));
        comboBox_Column->setItemText(4, QCoreApplication::translate("MainWindow", "Rating", nullptr));
        comboBox_Column->setItemText(5, QCoreApplication::translate("MainWindow", "People", nullptr));
        comboBox_Column->setItemText(6, QCoreApplication::translate("MainWindow", "ContactNumber", nullptr));
        comboBox_Column->setItemText(7, QCoreApplication::translate("MainWindow", "Years", nullptr));

        label_Column->setText(QCoreApplication::translate("MainWindow", "Column:", nullptr));
        label_Syntax->setText(QCoreApplication::translate("MainWindow", "Filter:", nullptr));
        label_DragNDrop->setText(QCoreApplication::translate("MainWindow", "Drag&Drop:", nullptr));
        comboBox_MimeType->setItemText(0, QString());
        comboBox_MimeType->setItemText(1, QCoreApplication::translate("MainWindow", "Qt Application", nullptr));
        comboBox_MimeType->setItemText(2, QCoreApplication::translate("MainWindow", "Text", nullptr));

        pushButton_Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
