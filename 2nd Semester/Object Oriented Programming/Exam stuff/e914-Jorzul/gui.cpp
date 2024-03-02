//
// Created by User on 6/14/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"


gui::gui(Repository& r, string _dep, QWidget *parent) :
        QWidget(parent), repo{ r } {
    ui.setupUi(this);

    populateList(_dep);
}

gui::~gui() {

}

void gui::populateList(string _dep) {
    int i = 1;

    for (auto g: this->repo.getDepartments())
    {
        QString itemInList = QString::fromStdString(g.getName());
        this->ui.AssignVolList->addItem(QString::number(i) + " - " + itemInList);
        i++;
    }
}
