#include "mainwindow.h"

#include <QApplication>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    static std::once_flag flag;
    MainWindow *w = new MainWindow;
    w->show();
    return a.exec();
}
