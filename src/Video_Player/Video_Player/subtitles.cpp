#include "subtitles.h"
#include <fstream>
#include <iostream>

using namespace std;

void Subtitles::read()
{
    fstream plik;
    plik.open("plik.txt",ios::in);
    if(plik.good()==false)
    {
        cout<<"ERROR open";
        return;
    }

}

void Subtitles::search(int actual_time)
{

}

void Subtitles::write()
{
    fstream plik;
    plik.open("test.txt",ios::app);
    if(plik.good()==false)
    {
        cout<<"ERROR open";
        return;
    }

    Subtitles object{};


    for (auto i : object.data)
    {
        plik << "<<";
        plik << i.begin;
        plik << ">>";
        for (auto x: i.contents)
        plik << x;
        plik << "<<";
        plik << i.end;
        plik << ">>";
        plik << '\n';
    }
    plik.close();

}
