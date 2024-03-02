//
// Created by User on 5/24/2023.
//

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test3.h"

class Test3 : public QMainWindow
{
    Q_OBJECT

public:
    Test3(QWidget *parent = nullptr);
    ~Test3();

private:
    Service GUI_service;

    Ui::Test3Class ui;

    void populate_List();
};
