#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#pragma once


#include "studentoSkaiciaustikrinimas.h"
#include "sveikoSkaiciausPatikriniams.h"
#include "duomenys.h"
#include "duom_rankinis.h"

vector<duomenys> duom_rankinis (vector<duomenys> A,int &n, string &pasirinkimas)
{
    cout<<"Iveskite studentu skaiciu: "<<endl;
    n = studentuskaiciaustikrinimas();
    duomenys s;
    for(int i=0; i<n; i++)
    {

        cout<<"Iveskite "<<i+1<<"-o varda ir pavarde: ";
        cin>>s.vardas>>s.pavarde;
        float suma=0;
        int pazymiu_skaicius = 0;
        cout<<"Iveskite "<<i+1<<"studento pazymius, kai baigsite vesti - iveskite 0"<<endl;
        float temp;
        cout<<"1 pazymis: ";
        while ((temp = sveikoSkaiciausPatikrinimas()) && (temp!=0))
        {
            cout<< pazymiu_skaicius + 2 <<" pazymis: ";
            s.pazymiai.push_back(temp);
            suma+=temp;
            pazymiu_skaicius++;

        }
        cout<<"Iveskite "<<i+1<<" studento egzamino rezultata: ";
        s.egzamino_rez = sveikoSkaiciausPatikrinimas();
        s.galutinis_egz = 0.4*(suma/(s.pazymiai.size()))+0.6*s.egzamino_rez;
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
