#include "subtitles.h"
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QString>

using namespace std;

Subtitles::Subtitles()
{
    actual=0;
    pathToRead="plik.txt";
    pathToWrite="test.txt";
}

void Subtitles::read()
{
    //qDebug()<<"ERROR 10";
    fstream plik;
    plik.open(this->pathToRead,ios::in);
     qDebug()<<QString::fromStdString(this->pathToRead);
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
        qDebug()<<QString::fromStdString(temp);
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
            qDebug()<<QString::fromStdString(temp);
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


Subtitle Subtitles::pop()
{
    if(this->actual<=this->data.size())
        return this->data[this->actual++];
    else {
        Subtitle s;
        s.begin=SIZE_MAX;
        s.end=SIZE_MAX;
        s.contents="";
        return s;
    }
}

void Subtitles::find(size_t msek)
{
    unsigned long i=0;
    for (auto j : this->data)
    {
        if(j.begin>msek) break;
        i++;
    }
    this->actual=i;
}

void Subtitles::write()
{
    //qDebug()<<"ERROR 0";
    fstream plik;
    plik.open(this->pathToWrite,ios::app);
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
