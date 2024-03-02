//
// Created by User on 6/13/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TestQtWidget.h" resolved

#include "testqtwidget.h"
#include "ui_TestQtWidget.h"


TestQtWidget::TestQtWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::TestQtWidget) {
    ui->setupUi(this);
}

TestQtWidget::~TestQtWidget() {
    delete ui;
}
