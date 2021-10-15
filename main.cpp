#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>

#include "duomenys.h"
#include "duom_automatinis.h"
#include "duom_rankinis.h"
#include "duom_isfailo.h"


using namespace std;

int main()
{
    int n;
    string pasirinkimas, duom_pasirinkimas;

    int pazSkaicius;
    vector<duomenys> A;

    cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai spauskite A, jeigu norite, kad duomenys nuskaitytu is failo spauskite - F";
    cin>>duom_pasirinkimas;
    if ((duom_pasirinkimas != "R") && (duom_pasirinkimas != "r") && (duom_pasirinkimas != "A") && (duom_pasirinkimas != "a")&& (duom_pasirinkimas != "F") && (duom_pasirinkimas != "f") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai spauskite A";
        cin>>duom_pasirinkimas;
    }

    if (duom_pasirinkimas == "R" || duom_pasirinkimas == "r")
    { A = duom_rankinis(A,n,pasirinkimas);  }
    else if (duom_pasirinkimas == "A" || duom_pasirinkimas == "a")
    { A = duom_automatinis(A,n,pasirinkimas); }
    else if (duom_pasirinkimas == "F" || duom_pasirinkimas == "f")
    {duom_isfailo(A,&pazSkaicius,pasirinkimas);}



    spausdinimas(A,pasirinkimas);
    cout<<":)"<<endl;

    return 0;

}
