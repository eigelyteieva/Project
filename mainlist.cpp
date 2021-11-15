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
using std::list;
using std::to_string;

struct duomenys{
    string vardas, pavarde;
    vector<float> pazymiai;
    float egzamino_rez;
    float galutinis_egz;
};
float mediana(vector<int> pazymiai)
{
    sort (pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
    {return pazymiai[pazymiai.size()/2];}
    else
    {return (double)(pazymiai[(pazymiai.size() - 1)/2]+pazymiai[pazymiai.size()/2])/2.0;}
}
float mediana1(vector<float> pazymiai)
{
    sort (pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
    {return pazymiai[pazymiai.size()/2];}
    else
    {return (double)(pazymiai[(pazymiai.size() - 1)/2]+pazymiai[pazymiai.size()/2])/2.0;}
}
std::vector<int> automatiniai_paz(int pazkiekis)
{
    int kiekis = rand() % 10+1 ;
	std::vector<int> rezultatai;
	for (int i = 0; i < pazkiekis; i++)
	{
		rezultatai.push_back(kiekis);
	}
	return rezultatai;
}
int duom_automatinis(vector<int> pazymiai)
{
    int failo_pasirinkimas;
    string pasirinkimas;
    int p;

    cout<<"Pasirinkite, kurio dydzio faila noresite sugeneruoti: 1 - 1000 duomenu, 2 - 10 000 duomenu, 3 - 100 000 duomenu, 4 - 1 000 000 duomenu, 5 - 10 000 000 duomenu"<<endl;
    cin>>failo_pasirinkimas;

    if (failo_pasirinkimas == 1) { p = 1000;}
    else if (failo_pasirinkimas == 2) {p = 10000;}
    else if (failo_pasirinkimas == 3) {p = 100000;}
    else if (failo_pasirinkimas == 4) {p = 1000000;}
    else if (failo_pasirinkimas == 5) {p = 10000000;}
    else {cout<<"Ivedete neteisinga simboli"<<endl;}

    cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M"<<endl;
    cin>>pasirinkimas;

    if ((pasirinkimas != "G") && (pasirinkimas != "g") && (pasirinkimas != "M") && (pasirinkimas != "m") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M";
        cin>>pasirinkimas;
    }

    vector<int> rezultatai;
    string pavadinimas = to_string(p) + ".txt";
    std::ofstream isve(pavadinimas);
    duomenys A;

    isve<<setw(20)<<std::left<<"Vardas"
    <<setw(20)<<std::left<<"Pavarde";
    if (pasirinkimas == "G" || pasirinkimas == "g")
    {isve<<std::left<<"Galutinis(egz.)\n";}
    else{isve<<std::left<<"Mediana\n";}
    for(int k=1; k <= p; k = k+1)
    {
         rezultatai = automatiniai_paz(10);
         int egzamino_rez = rand() %10+1;
         float galutinis_egz = 0.4 * std::accumulate(rezultatai.begin(), rezultatai.end(), 0) / rezultatai.size() + 0.6 *egzamino_rez ;

         isve<<setw(20)<<"Vardas"+to_string(k)<<setw(20)<<"Pavarde"+to_string(k);
         if (pasirinkimas == "G" || pasirinkimas == "g")
            {isve<<setw(20)<<std::setprecision(3)<<galutinis_egz<<endl;}
         else{isve<<setw(20)<<std::setprecision(3)<<mediana(rezultatai)<<endl;}
         rezultatai.clear();
    }
    return p;
}
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
int sveikoSkaiciausPatikrinimas()
{
    string laikinas;
    int temp;
    while(1){
        cin>>laikinas;
        if(isNumber(laikinas) == true){
            temp = stoi(laikinas);
            if(((temp >= 0) && (temp <= 10)))
            break;
            else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
        }
        else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
    }
    return temp;
}
int studentuskaiciaustikrinimas()
{
    string laikinas;
    int temp;
    while(1){
        cin>>laikinas;
        if(isNumber(laikinas) == true){
            temp = stoi(laikinas);
            if(((temp >= 0) && (temp <= 100)))
            break;
            else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
        }
        else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
    }
    return temp;
}
list<duomenys> duom_rankinis (list<duomenys> A,int &p, string &pasirinkimas)
{
    cout<<"Iveskite studentu skaiciu: "<<endl;
    p = studentuskaiciaustikrinimas();
    duomenys s;
    for(int i=0; i<p; i++)
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
void spausdinimas (list<duomenys> A,string pasirinkimas, int p)
{

    string pavadinimas = to_string(p) + ".txt";
    std::ofstream isve;
    isve.open(pavadinimas);
    isve<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde";
    if (pasirinkimas == "G" || pasirinkimas == "g")
    {isve<<setw(20)<<std::left<<"Galutinis(egz.)\n";}
    else{isve<<setw(20)<<std::left<<"Mediana\n";}
    isve<<"-------------------------------------------------------\n";
    for (int i=0; i<A.size(); i++)
    {
        auto s = std::next(A.begin(), i);
        isve<<setw(20)<<(*s).vardas<<setw(20)<<(*s).pavarde;
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {isve<<setw(20)<<std::setprecision(2)<<(*s).galutinis_egz<<endl;}
        else{isve<<setw(20)<<mediana1((*s).pazymiai)<<endl;}
    }
    isve<<"\n\n";
}

void skaitymas(list<duomenys>& A,int p)
{
    int studentu_sk =0 ;
    std::ifstream duom;
    string k;
    string pavadinimas = to_string(p)+".txt";

    duom.open(pavadinimas);
    if(duom.is_open())
    {
        getline(duom>>std::ws, k);

        while(studentu_sk < p)
        {
            duomenys data;
            duom>>data.vardas;
            duom>>data.pavarde;
            duom>>data.galutinis_egz;
            A.push_back(data);
            studentu_sk++;
        }
    }
}
 void paskirstymas(list<duomenys> A,int p,list<duomenys> &vargsiukai,list<duomenys> &kietekai)
{
    for (int i=0; i < A.size(); i++)
    {
        auto s = std::next(A.begin(), i);

        if((*s).galutinis_egz < 5.00)
        {
            vargsiukai.push_back(*s);
        }
        else if ((*s).galutinis_egz >= 5.00)
        {
            kietekai.push_back(*s);
        }
    }
}
void paskirstymo_isve(list<duomenys> vargsiukai, list<duomenys> kietekai)
{
    std::ofstream duom_maz5("vargsiukai.txt");
    std::ofstream duom_daug5("kietekai.txt");
    for (int i=0; i<vargsiukai.size(); i++)
    {
        auto s = std::next(vargsiukai.begin(),i);
        duom_maz5<<setw(20)<<std::left<<s->vardas<<setw(20)<<std::left<<s->pavarde<<setw(20)<<std::left<<s->galutinis_egz<<endl;
    }
    duom_maz5.close();

    for (int i=0; i<kietekai.size(); i++)
    {
        auto s = std::next(kietekai.begin(),i);
        duom_daug5<<setw(20)<<std::left<<s->vardas<<setw(20)<<std::left<<s->pavarde <<setw(20)<<std::left<<s->galutinis_egz<<endl;
    }
    duom_daug5.close();
}
int main()
{
    list<duomenys> D;
    string duom_pasirinkimas,pasirinkimas;
    int p;
    int n;
    int B;
    int C;
    cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai i faila spauskite A";
    cin>>duom_pasirinkimas;
    if ((duom_pasirinkimas != "R") && (duom_pasirinkimas != "r") && (duom_pasirinkimas != "A") && (duom_pasirinkimas != "a"))
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai spauskite A";
        cin>>duom_pasirinkimas;
    }

    std::clock_t start, all;
    if (duom_pasirinkimas == "R" || duom_pasirinkimas == "r")
    {
        D=duom_rankinis(D,p,pasirinkimas);
        spausdinimas(D,pasirinkimas,p);

        list<duomenys> varg;
        list<duomenys> kiete;

        paskirstymas(D,p,varg,kiete);
        paskirstymo_isve(varg,kiete);

    }
    else
    {
        vector<int>rezultatai;
        B = duom_automatinis(rezultatai);

    start=std::clock();
    skaitymas(D,B);
    double duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"SKAITYMAS UZTRUKO"<<duration<<"s"<<endl;

    start=std::clock();

    list<duomenys> varg;
    list<duomenys> kiete;

    paskirstymas(D,B,varg,kiete);
    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Skirstymas uztruko"<<duration<<"s"<<endl;

    paskirstymo_isve(varg,kiete);
    }

    cout<<":)"<<endl;

    return 0;

}


