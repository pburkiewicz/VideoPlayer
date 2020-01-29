#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <vector>
#include <string>
#include <QWidget>

using namespace std;

struct Subtitle
{
    int begin;
    string contents;
    int end;
};


class Subtitles:public QWidget
{
public:
    vector <Subtitle> data;
    int actual=0;

    void read();
    void write();
    Subtitle push();
    void find(int msek);
};

#endif // SUBTITLES_H
