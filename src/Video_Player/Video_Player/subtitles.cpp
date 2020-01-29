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
