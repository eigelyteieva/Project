#ifndef DUOM_AUTOMATINIS_H_INCLUDED
#define DUOM_AUTOMATINIS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "studentoSkaiciaustikrinimas.h"
#include "duomenys.h"

using std::vector;

vector<duomenys> duom_automatinis (vector<duomenys> A,int n,string &pasirinkimas);

#endif // DUOM_AUTOMATINIS_H_INCLUDED
