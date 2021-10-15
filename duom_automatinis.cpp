#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#pragma once


#include "studentoSkaiciaustikrinimas.h"
#include "duomenys.h"
#include "duom_automatinis.h"

vector<duomenys> duom_automatinis (vector<duomenys> A,int n,string &pasirinkimas)
{
    cout<<"Iveskite studentu skaiciu: "<<endl;
    n = studentuskaiciaustikrinimas();
    srand(time(NULL));
    duomenys s;
    float suma, temp;
    for (int e=0; e<n; e++)
    {   suma = 0;
        cout<<"Iveskite "<<e+1<<"-o varda ir pavarde: ";
        cin>>s.vardas>>s.pavarde;
        for(int i= 0; i<rand() % 10 + 1; i++)
        {
            temp = rand() % 10 + 1;
            s.pazymiai.push_back(temp);
            suma+= temp;
        }
        s.egzamino_rez = rand() % 10 + 1;
        s.galutinis_egz =0.4*(suma/s.pazymiai.size())+0.6*s.egzamino_rez;
        A.push_back(s);
    }
    cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M"<<endl;
    cin>>pasirinkimas;
    if ((pasirinkimas != "G") && (pasirinkimas != "g") && (pasirinkimas != "M") && (pasirinkimas != "m") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M";
        cin>>pasirinkimas;
    }
    return A;
}
