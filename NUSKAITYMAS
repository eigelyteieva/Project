#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::ifstream;
using std::sort;
using std::vector;

struct duomenys{
    string vardas, pavarde;
    vector<float> pazymiai = {0};
    float egzamino_rez;
    float galutinis_egz;
};
/*void rikiavimas(vector<duomenys>& A)
{
    for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<A.size()-1;j++)
        {
            if (A[j].vardas < A[j].vardas)
            {
                std::swap (A[i],A[j]);
            }
        }
    }
}*/

float mediana(vector<float> pazymiai)
{
    sort (pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
    {return pazymiai[pazymiai.size()/2];}
    else
    {return (double)(pazymiai[(pazymiai.size() - 1)/2]+pazymiai[pazymiai.size()/2])/2.0;}
}


void spausdinimas (vector<duomenys> A, int pazymiu_skaicius)
{
    std::ofstream output;
    output.open("rez.txt");
    output<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde"<<
    setw(20)<<std::left<<"Galutinis"<<setw(20)<<std::left<<"Mediana"<<endl;

    cout<<"-------------------------------------------------------\n";

    for(int i=0; i<A.size();i++)
    {

        output<<setw(20)<<std::left<<A[i].vardas<<setw(20)<<std::left<<A[i].pavarde<<
    setw(20)<<std::left<<std::setprecision(2)<<A[i].galutinis_egz<<mediana(A[i].pazymiai)<<endl;


    }
    output<<"\n\n";

}

unsigned int skaiciukas(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
ifstream duom("kursiokai.txt");
void skaitymas (vector<duomenys> & A,int* pazSkaicius)
{
    int studentu_sk;
    int temp;
    string k;
    ifstream duom("kur.txt");
    if(duom.is_open())
    {

        getline(duom>>std::ws, k);
        *pazSkaicius = skaiciukas(k)-3;

        while(!(cin.fail()))
        {
            float suma=0;
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
    }
    else {cout<<"-\n";}
    duom.close();
}

int main()
{
    int pazymiu_skaicius;
    char temp;

    vector<duomenys> A;

    skaitymas(A,&pazymiu_skaicius);
    spausdinimas(A,pazymiu_skaicius);

    system("pause");
    return 0;

}








