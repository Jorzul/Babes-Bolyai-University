/********************************************************************************
** Form generated from reading UI file 'user_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_WINDOW_H
#define UI_USER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *reportsListWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *chatListWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *chatLineEdit;
    QPushButton *sendPushButton;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *descLabel;
    QLineEdit *descLineEdit;
    QLabel *latiLabel;
    QLineEdit *latiLineEdit;
    QLabel *longiLabel;
    QLineEdit *longiLineEdit;
    QLabel *locationLabel;
    QLineEdit *locationLineEdit;
    QLabel *scoreLabel;
    QLineEdit *scoreLineEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addPushButton;
    QPushButton *validatePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(648, 467);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        reportsListWidget = new QListWidget(centralwidget);
        reportsListWidget->setObjectName("reportsListWidget");

        horizontalLayout_2->addWidget(reportsListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        chatListWidget = new QListWidget(centralwidget);
        chatListWidget->setObjectName("chatListWidget");

        verticalLayout->addWidget(chatListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        chatLineEdit = new QLineEdit(centralwidget);
        chatLineEdit->setObjectName("chatLineEdit");

        horizontalLayout->addWidget(chatLineEdit);

        sendPushButton = new QPushButton(centralwidget);
        sendPushButton->setObjectName("sendPushButton");

        horizontalLayout->addWidget(sendPushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        descLabel = new QLabel(centralwidget);
        descLabel->setObjectName("descLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, descLabel);

        descLineEdit = new QLineEdit(centralwidget);
        descLineEdit->setObjectName("descLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, descLineEdit);

        latiLabel = new QLabel(centralwidget);
        latiLabel->setObjectName("latiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, latiLabel);

        latiLineEdit = new QLineEdit(centralwidget);
        latiLineEdit->setObjectName("latiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, latiLineEdit);

        longiLabel = new QLabel(centralwidget);
        longiLabel->setObjectName("longiLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, longiLabel);

        longiLineEdit = new QLineEdit(centralwidget);
        longiLineEdit->setObjectName("longiLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, longiLineEdit);

        locationLabel = new QLabel(centralwidget);
        locationLabel->setObjectName("locationLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, locationLabel);

        locationLineEdit = new QLineEdit(centralwidget);
        locationLineEdit->setObjectName("locationLineEdit");
        locationLineEdit->setEnabled(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, locationLineEdit);

        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName("scoreLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, scoreLabel);

        scoreLineEdit = new QLineEdit(centralwidget);
        scoreLineEdit->setObjectName("scoreLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, scoreLineEdit);


        horizontalLayout_3->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        addPushButton = new QPushButton(centralwidget);
        addPushButton->setObjectName("addPushButton");

        verticalLayout_2->addWidget(addPushButton);

        validatePushButton = new QPushButton(centralwidget);
        validatePushButton->setObjectName("validatePushButton");

        verticalLayout_2->addWidget(validatePushButton);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 648, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sendPushButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        descLabel->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        latiLabel->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        longiLabel->setText(QCoreApplication::translate("MainWindow", "Longitude:", nullptr));
        locationLabel->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        addPushButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        validatePushButton->setText(QCoreApplication::translate("MainWindow", "Validate", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_WINDOW_H
