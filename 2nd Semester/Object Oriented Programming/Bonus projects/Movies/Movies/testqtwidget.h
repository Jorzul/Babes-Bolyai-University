//
// Created by User on 6/13/2023.
//

#ifndef NORBI_TESTQTWIDGET_H
#define NORBI_TESTQTWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TestQtWidget; }
QT_END_NAMESPACE

class TestQtWidget : public QWidget {
    Q_OBJECT

public:
    explicit TestQtWidget(QWidget *parent = nullptr);

    ~TestQtWidget() override;

private:
    Ui::TestQtWidget *ui;
};


#endif //NORBI_TESTQTWIDGET_H
