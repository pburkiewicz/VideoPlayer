#include "mainwindow.h"
#include "subtitles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    auto xx= new Subtitles;

    //xx->write();
    xx->write();
    return a.exec();
}
