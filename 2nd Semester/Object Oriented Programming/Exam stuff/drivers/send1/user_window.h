#pragma once
#include <set>
#include <QMainWindow>
#include "repository.h"
#include "observer.h"
#include "session.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE


class UserWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    UserWindow(int, Session &sess, Repository &repo, QWidget *parent = nullptr);

    ~UserWindow() override;

    void update(const int reporter_idx) override;

private:
    Ui::UserWindow *ui;
    Repository &repo;
    Session &sess;
    int cur_idx;
    std::set<std::pair<int, int>> validated;

    void populateReportsList();

    void populateChatList();
};
