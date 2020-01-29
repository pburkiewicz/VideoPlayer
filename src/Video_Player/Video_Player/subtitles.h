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
    size_t actual=0;
    string pathToRead;
    string pathToWrite;

    Subtitles();
    void read();
    void write();
    Subtitle pop();
    void find(int msek);
};

#endif // SUBTITLES_H
