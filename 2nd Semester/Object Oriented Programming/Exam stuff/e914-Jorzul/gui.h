//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_GUI_H
#define E914_JORZUL_GUI_H

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include "repository.h"
#include "ui_gui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

public:
    gui(Repository& r, string _dep, QWidget *parent = nullptr);

    ~gui() override;

    void populateList(string _dep);

private:
    Ui::gui ui;
    Repository& repo;
};


#endif //E914_JORZUL_GUI_H
