/********************************************************************************
** Form generated from reading UI file 'arraywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARRAYWINDOW_H
#define UI_ARRAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_arrayWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QTableWidget *tableWidget;
    QPushButton *startButton;
    QPushButton *continueButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *arrayWindow)
    {
        if (arrayWindow->objectName().isEmpty())
            arrayWindow->setObjectName(QStringLiteral("arrayWindow"));
        arrayWindow->resize(959, 553);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../OneDrive/Obr\303\241zky/apex/arraypng.png"), QSize(), QIcon::Normal, QIcon::Off);
        arrayWindow->setWindowIcon(icon);
        centralWidget = new QWidget(arrayWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setPointSize(20);
        nameLabel->setFont(font);

        verticalLayout->addWidget(nameLabel);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout->addWidget(startButton);

        continueButton = new QPushButton(centralWidget);
        continueButton->setObjectName(QStringLiteral("continueButton"));

        verticalLayout->addWidget(continueButton);


        verticalLayout_2->addLayout(verticalLayout);

        arrayWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(arrayWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 959, 21));
        arrayWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(arrayWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        arrayWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(arrayWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        arrayWindow->setStatusBar(statusBar);

        retranslateUi(arrayWindow);

        QMetaObject::connectSlotsByName(arrayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *arrayWindow)
    {
        arrayWindow->setWindowTitle(QApplication::translate("arrayWindow", "Interpreter", nullptr));
        nameLabel->setText(QApplication::translate("arrayWindow", "TextLabel", nullptr));
        startButton->setText(QApplication::translate("arrayWindow", "Start", nullptr));
        continueButton->setText(QApplication::translate("arrayWindow", "Pokracovat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class arrayWindow: public Ui_arrayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARRAYWINDOW_H
