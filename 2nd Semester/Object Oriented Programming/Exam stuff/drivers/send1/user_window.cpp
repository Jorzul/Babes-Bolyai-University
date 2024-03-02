#include "user_window.h"
#include <QFont>
#include <QListWidgetItem>
#include <QPushButton>
#include <QString>
#include "ui_user_window.h"
#include <fstream>
#include <QMessageBox>
#include <string>


UserWindow::UserWindow(int _cur_idx, Session &_sess, Repository &_repo, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
    , repo{_repo}
    , sess{_sess}
    , cur_idx{_cur_idx}
{
    ui->setupUi(this);
    auto &cur_driver = this->repo.get_drivers()[this->cur_idx];
    this->setWindowTitle(QString::fromStdString(cur_driver.get_name()));
    std::string location = std::to_string(cur_driver.get_lati()) + ", " + std::to_string(cur_driver.get_longi());
    this->ui->locationLineEdit->setText(QString::fromStdString(location));
    this->ui->locationLineEdit->setEnabled(false);
    this->ui->scoreLineEdit->setText(QString::number(cur_driver.get_score()));
    this->ui->scoreLineEdit->setEnabled(false);
    this->populateReportsList();

    // add report
    QObject::connect(this->ui->addPushButton, &QPushButton::clicked, this, [&]()
    {
        auto desc = this->ui->descLineEdit->text().toStdString();
        auto lati = this->ui->latiLineEdit->text().toInt();
        auto longi = this->ui->longiLineEdit->text().toInt();
        auto &cur_driver = this->repo.get_drivers()[this->cur_idx];
        auto name = cur_driver.get_name();
        this->ui->descLineEdit->clear();
        this->ui->latiLineEdit->clear();
        this->ui->longiLineEdit->clear();

        if (desc.empty() || ((cur_driver.get_lati() - lati) * (cur_driver.get_lati() - lati)
            + (cur_driver.get_longi() - longi) * (cur_driver.get_longi() - longi) > 20 * 20))
        {
            QMessageBox::critical(this, QString("Error"), QString("Description is empty or report is too far away."));
            return;
        }

        this->sess.add(desc, name, lati, longi, "false");
    });

    // validate report
    QObject::connect(this->ui->validatePushButton, &QPushButton::clicked, this, [&]()
    {
        const auto &cur_text = this->ui->reportsListWidget->selectedItems().at(0)->text().toStdString();
        std::string cur_elem;
        std::vector<std::string> elems;
        for (int i = 0, size = cur_text.size(); i < size; ++i)
        {
            if (cur_text[i] == ',')
            {
                elems.emplace_back(cur_elem);
                cur_elem = "";
            }
            else if (cur_text[i] != ' ')
            {
                cur_elem += cur_text[i];
            }
        }
        elems.emplace_back(cur_elem);
        auto report = Report(elems[0], elems[1], std::stoi(elems[2]), std::stoi(elems[3]), elems.back() == "false" ? 0 : 1);
        if (this->validated.count({report.get_longi(), report.get_lati()}))
        {
            return;
        }
        this->validated.emplace(report.get_longi(), report.get_lati());
        auto &reporter = elems[1];
        auto &drivers = this->repo.get_drivers();
        int reporter_idx;
        for (int i = 0; ; ++i)
        {
            if (drivers[i].get_name() == reporter)
            {
                reporter_idx = i;
                break;
            }
        }
        auto &reports = this->repo.get_reports();
        int report_idx;
        for (int i = 0; ; ++i)
        {
            if (report.get_lati() == reports[i].get_lati() && report.get_longi() == reports[i].get_longi())
            {
                report_idx = i;
                break;
            }
        }
        this->sess.validate(report_idx, reporter_idx);
    });

    // send text to chat
    QObject::connect(this->ui->sendPushButton, &QPushButton::clicked, this, [&]()
    {
        auto &cur_driver = this->repo.get_drivers()[this->cur_idx];
        const std::string text = cur_driver.get_name() + ": " + this->ui->chatLineEdit->text().toStdString();
        this->ui->chatLineEdit->clear();
        this->sess.send(text);
    });
}


void UserWindow::populateReportsList()
{
    this->ui->reportsListWidget->clear();
    const auto &cur_driver = this->repo.get_drivers()[this->cur_idx];
    auto &reports = this->repo.get_reports();
    for (auto &report : reports)
    {
        if (!((cur_driver.get_lati() - report.get_lati()) * (cur_driver.get_lati() - report.get_lati())
            + (cur_driver.get_longi() - report.get_longi()) * (cur_driver.get_longi() - report.get_longi()) <= 10 * 10))
        {
            continue;
        }
        const auto str_report = report.get_desc() + ", " + report.get_reporter() + ", "
                                + std::to_string(report.get_lati()) + ", "
                                + std::to_string(report.get_longi()) + ", "
                                + (report.get_status() ? "true" : "false");
        auto cur_item = new QListWidgetItem(QString::fromStdString(str_report));
        if (report.get_status())
        {
            QFont boldFont;
            boldFont.setBold(true);
            cur_item->setFont(boldFont);
            cur_item->setFlags(cur_item->flags() & ~Qt::ItemIsSelectable);
        }
        if (report.get_reporter() == cur_driver.get_name() || this->validated.count({report.get_longi(), report.get_lati()}))
        {
            cur_item->setFlags(cur_item->flags() & ~Qt::ItemIsSelectable);
        }
        this->ui->reportsListWidget->addItem(cur_item);
    }
}


void UserWindow::populateChatList()
{
    this->ui->chatListWidget->clear();
    const auto &chat_text = this->repo.get_chat_text();
    for (const auto &line : chat_text)
    {
        this->ui->chatListWidget->addItem(QString::fromStdString(line));
    }
}


void UserWindow::update(const int reporter_idx)
{
    this->populateReportsList();
    this->populateChatList();
    if (reporter_idx != -1)
    {
        const auto &cur_driver = this->repo.get_drivers()[this->cur_idx];
        const auto &reporter_driver = this->repo.get_drivers()[reporter_idx];
        if (cur_driver.get_name() == reporter_driver.get_name())
        {
            this->ui->scoreLineEdit->setText(QString::number(cur_driver.get_score()));
        }
    }
}


UserWindow::~UserWindow()
{
    delete ui;
    this->repo.save_to_file();
}
