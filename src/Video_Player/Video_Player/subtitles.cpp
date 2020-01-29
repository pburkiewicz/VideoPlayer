#include "subtitles.h"
#include <fstream>
#include <iostream>
#include <QDebug>

using namespace std;

void Subtitles::read()
{
    //qDebug()<<"ERROR 10";
    fstream plik;
    plik.open("plik.txt",ios::in);
    if(plik.good()==false)
    {
        qDebug()<<"ERROR open";
        return;
    }

    for(int i=0;i<5;i++)
    {
        //qDebug()<<"ERROR 11";
        Subtitle s;
        string temp;
        plik>>temp;
        if (temp=="<<")
        {
            plik>>s.begin;
        }
        plik>>temp;// wczytaj >>
        temp="";
        while(temp!="<<")
        {
            s.contents+=(temp+" ");
            plik>>temp;
        }
        //qDebug()<<"ERROR 12";
        plik>>s.end;
        plik>>temp;
        this->data.push_back(s);
        continue;
    }
    this->data.shrink_to_fit();
    plik.close();
}


Subtitle Subtitles::push()
{
    return this->data[this->actual++];
}

void Subtitles::find(int msek)
{
    int i=-1;
    for (auto j : this->data)
    {
        i++;
        if(j.begin>msek) break;
    }
    this->actual=i;
}

void Subtitles::write()
{
    //qDebug()<<"ERROR 0";
    fstream plik;
    plik.open("test.txt",ios::app);
    if(plik.good()==false)
    {
        qDebug()<<"ERROR open";
        return;
    }

    for (auto i : this->data)
    {
        //qDebug()<<"ERROR 1";
        plik << "<< ";
        plik << i.begin;
        plik << " >>";
        plik << i.contents;
        plik << "<< ";
        plik << i.end;
        plik << " >>\n";
    }
    plik.close();

}
