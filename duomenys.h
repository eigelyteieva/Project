#ifndef DUOMENYS_H_INCLUDED
#define DUOMENYS_H_INCLUDED
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::istream;
using std::sort;
using std::vector;
#pragma once

#include <string>
#include <vector>


struct duomenys{
    std::string vardas, pavarde;
    std::vector<float> pazymiai = {0};
    float egzamino_rez;
    float galutinis_egz;
};


#endif // DUOMENYS_H_INCLUDED
