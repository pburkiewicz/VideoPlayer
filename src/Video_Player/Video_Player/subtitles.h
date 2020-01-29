#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <vector>
#include <QWidget>

using namespace std;

struct Subtitle
{
    int begin;
    vector <char> contents;
    int end;
};


class Subtitles:public QWidget
{
    vector <Subtitle> data;

    void read();
    void search(int actual_time);
    //void
};

#endif // SUBTITLES_H
