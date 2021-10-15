#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include "spausdinimas.h"
#include "mediana.h"
#pragma once

using std::vector;

void spausdinimas (vector<duomenys> A,string pasirinkimas)
{

    std::ofstream output;
    output.open("rez1.txt");
    output<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde";
    if (pasirinkimas == "G" || pasirinkimas == "g")
    {output<<setw(20)<<std::left<<"Galutinis(egz.)\n";}
    else{output<<setw(20)<<std::left<<"Mediana\n";}
    output<<"-------------------------------------------------------\n";
    for (int i=0; i<A.size(); i++)
    {
        output<<setw(20)<<A[i].vardas<<setw(20)<<A[i].pavarde;
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {output<<setw(20)<<std::setprecision(2)<<A[i].galutinis_egz<<endl;}
        else{output<<setw(20)<<mediana(A[i].pazymiai)<<endl;}
    }
    output<<"\n\n";
}
