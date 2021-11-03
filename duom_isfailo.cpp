#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <vector>
#include <fstream>
#include <iterator>
#pragma once

#include "skaiciukas.h"
#include "duom_isfailo.h"

void duom_isfailo (vector<duomenys> & A,int* pazSkaicius, string &pasirinkimas)
{
    int studentu_sk;
    int temp;
    int failo_pasirinkimas;
    string k;
    string p;

    cout<<"Pasirinkite, kurio dydzio faila noresite sugeneruoti: 1 - 1000 duomenu, 2 - 10 000 duomenu, 3 - 100 000 duomenu"<<endl;
    cin>>failo_pasirinkimas;

    if (failo_pasirinkimas == 1) { p = "1000.txt";}
    else if (failo_pasirinkimas == 2) {p = "10000.txt";}
    else if (failo_pasirinkimas == 3) {p = "100000.txt";}

    std::ifstream duom;
    try{
        duom.open(p);

    if(!duom.is_open())
        throw 0;

        getline(duom>>std::ws, k);
        *pazSkaicius = skaiciukas(k) - 3;
        while(!(cin.fail()))
        {   float suma=0;
            A.resize(A.size()+1);
            duom>>A.at(studentu_sk).vardas;
            if(duom.eof())
                {A.pop_back();
                break;}
            duom>>A.at(studentu_sk).pavarde;
            for(int i=0; i< *pazSkaicius; i++)
            {
                duom>>temp;
                A.at(studentu_sk).pazymiai.push_back(temp);
                suma+=temp;
            }
            duom>>A.at(studentu_sk).egzamino_rez;
            A.at(studentu_sk).galutinis_egz = 0.4 * (suma/(A.at(studentu_sk).pazymiai.size()-1))+ 0.6 * A.at(studentu_sk).egzamino_rez;
            studentu_sk++;
        }
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M"<<endl;
    cin>>pasirinkimas;
     if ((pasirinkimas != "G") && (pasirinkimas != "g") && (pasirinkimas != "M") && (pasirinkimas != "m") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M";
        cin>>pasirinkimas;
    }
    }
    catch(int e)
    {
        cout<<"Tokio failo nera/Ivedete neteisinga failo pavadinima"<<endl;

    }

}

