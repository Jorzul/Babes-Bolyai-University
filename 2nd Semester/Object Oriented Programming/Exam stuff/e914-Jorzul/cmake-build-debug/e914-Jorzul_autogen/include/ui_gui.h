/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *AssignVolList;
    QListWidget *UnassigVolList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *interestLineEdit;
    QPushButton *addButton;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        verticalLayout = new QVBoxLayout(gui);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AssignVolList = new QListWidget(gui);
        AssignVolList->setObjectName("AssignVolList");

        horizontalLayout->addWidget(AssignVolList);

        UnassigVolList = new QListWidget(gui);
        UnassigVolList->setObjectName("UnassigVolList");

        horizontalLayout->addWidget(UnassigVolList);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NameLabel = new QLabel(gui);
        NameLabel->setObjectName("NameLabel");

        horizontalLayout_2->addWidget(NameLabel);

        nameLineEdit = new QLineEdit(gui);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(gui);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        emailLineEdit = new QLineEdit(gui);
        emailLineEdit->setObjectName("emailLineEdit");

        horizontalLayout_3->addWidget(emailLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(gui);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        interestLineEdit = new QLineEdit(gui);
        interestLineEdit->setObjectName("interestLineEdit");

        horizontalLayout_4->addWidget(interestLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        addButton = new QPushButton(gui);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);


        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        NameLabel->setText(QCoreApplication::translate("gui", "Name", nullptr));
        label->setText(QCoreApplication::translate("gui", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "Interests", nullptr));
        addButton->setText(QCoreApplication::translate("gui", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
