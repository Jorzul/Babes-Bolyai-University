#include "user_window.h"
#include "repository.h"
#include "session.h"
#include <QApplication>
#include <vector>
#include <memory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo(R"(C:\Users\Robert\Desktop\qt creaaaator\oop_practical_exam\drivers.txt)",
                    R"(C:\Users\Robert\Desktop\qt creaaaator\oop_practical_exam\reports.txt)");
    Session sess(repo);
    int nr_drivers = repo.get_drivers().size();
    std::vector<std::shared_ptr<UserWindow>> windows;
    for (int i = 0; i < nr_drivers; ++i)
    {
        std::shared_ptr<UserWindow> window = std::make_shared<UserWindow>(i, sess, repo);
        sess.add_observer(window);
        window->show();
        windows.emplace_back(window);
    }
    return a.exec();
}
