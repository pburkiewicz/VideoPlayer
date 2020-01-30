#include "mainwindow.h"
#include "subtitles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    auto xx= new Subtitles;

    Subtitle s;
    s.end=7;
    s.begin=3;
    s.contents.push_back('a');
    s.contents.push_back('a');
    s.contents.push_back('a');
    xx->data.push_back(s);

    xx->read();
    xx->write();
    */
    return a.exec();
}
