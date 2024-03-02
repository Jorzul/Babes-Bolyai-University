#include "QtWidgetsApplication1.h"
#include "repository.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->populateList();
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::populateList()
{
    this->ui.listWidget->clear();
    int cars_size;

    Car* allCars = get_all_cars(&cars_size);

    for (int index = 0; index <= cars_size; index++)
    {
        this->ui.listWidget->addItem(QString::fromStdString(get_name(allCars[index]) + ' | ' + get_model(allCars[index])));
    }
}
