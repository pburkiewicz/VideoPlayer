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
    }
    Subtitle s;
    while(!plik.eof())
    {
        this->data.push_back(s);
        char temp;
        char temp2;
        plik>>temp;
        if (temp=='<')
        {
            plik>>temp2;
            if(temp2=='<')
                plik>>this->data.back().begin;
        }
        plik>>temp;
        plik>>temp;// wczytaj >>
        plik>>temp;
        while(temp!='<')
        {
            this->data.back().contents.push_back(temp);
            plik>>temp;
        }
        plik>>temp2;
        if(temp2=='<')
            plik>>this->data.back().end;
        plik>>temp;
        plik>>temp;// wczytaj >>
        continue;
    }
    plik.close();
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
