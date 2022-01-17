#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <fstream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::istream;
using std::sort;
using std::vector;
using std::to_string;

struct duomenys{
    string vardas, pavarde;
    vector<float> pazymiai;
    float egzamino_rez;
    float galutinis_egz;
    float galutinis_med;
};
float mediana(vector<float> pazymiai)
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
/*std::vector<int> automatiniai_paz(int pazkiekis)
{
    int kiekis = rand() % 10+1 ;
	std::vector<int> rezultatai;
	for (int i = 0; i < pazkiekis; i++)
	{
		rezultatai.push_back(kiekis);
	}
	return rezultatai;
}*/
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
vector<duomenys> duom_rankinis (vector<duomenys> A,int &p, string &pasirinkimas)
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
        s.galutinis_med = 0.4*mediana1(s.pazymiai)+0.6*s.egzamino_rez;
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
void spausdinimas (vector<duomenys> A,string pasirinkimas, int p)
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
        isve<<setw(20)<<A[i].vardas<<setw(20)<<A[i].pavarde;
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {isve<<setw(20)<<std::setprecision(2)<<A[i].galutinis_egz<<endl;}
        else{isve<<setw(20)<<A[i].galutinis_med<<endl;}
    }
    isve<<"\n\n";
}

void skaitymas(vector<duomenys>& A,int p)
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
            for(int i=0; i<7; i++){
               int skaiciukas;
               duom>>skaiciukas;
               data.pazymiai.push_back(skaiciukas);
            }
            duom>>data.egzamino_rez;
            float galutinis_egzas = 0.4 * std::accumulate(data.pazymiai.begin(), data.pazymiai.end(), 0) / data.pazymiai.size() + 0.6 *data.egzamino_rez;
            data.galutinis_egz = galutinis_egzas;
            float galutinis_mediana = 0.4 * mediana(data.pazymiai) + 0.6 *data.egzamino_rez ;
            data.galutinis_med = galutinis_mediana;
            A.push_back(data);
            studentu_sk++;
        }
    }
}
bool isSmallerThan5(float skaiciuks){
if(skaiciuks<5) return true;
else false;
}
 void paskirstymas(vector<duomenys> &A,vector<duomenys> &vargsiukai)
{
    for (int i=0; i<A.size(); i++)
    {
        if(A[i].galutinis_egz < 5.00)
        {   bool b = true;
            vargsiukai.push_back(A[i]);
            A.erase(A.begin() + i);
            i--;
        }
    }
}
void paskirstymo_isve(vector<duomenys> A, vector<duomenys> vargsiukai,string pasirinkimas, int p)
{
    string pavadinimas = to_string(p)+".txt";
    ofstream failas(pavadinimas, ofstream::trunc);
    spausdinimas (A,pasirinkimas,p);

    std::ofstream duom_maz5("vargsiukai.txt");

    for (auto i=0; i<vargsiukai.size(); i++)
    {

        duom_maz5<<setw(20)<<std::left<<vargsiukai[i].vardas<<setw(20)<<std::left<<vargsiukai[i].pavarde<<setw(20)<<std::left<<vargsiukai[i].galutinis_egz<<endl;
    }
    duom_maz5.close();
}
void duokiteRinktis(int &p, string &pasirinkimas){
    int failo_pasirinkimas;
    cout<<"Pasirinkite, kurio dydzio faila noresite nuskaityti: 1 - 1000 duomenu, 2 - 10 000 duomenu, 3 - 100 000 duomenu, 4 - 1 000 000 duomenu, 5 - 10 000 000 duomenu"<<endl;
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

}

int main()
{

    vector<duomenys> A;
    string duom_pasirinkimas,pasirinkimas;
    int p;
    int n;
    int B;
    int C;
    cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys butu nuskaityti is failo spauskite F";
    cin>>duom_pasirinkimas;
    if ((duom_pasirinkimas != "R") && (duom_pasirinkimas != "r") && (duom_pasirinkimas != "F") && (duom_pasirinkimas != "f"))
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai spauskite A";
        cin>>duom_pasirinkimas;
    }

    std::clock_t start, all;
    if (duom_pasirinkimas == "R" || duom_pasirinkimas == "r")
    {
        A=duom_rankinis(A,p,pasirinkimas);
        spausdinimas(A,pasirinkimas,p);

    start=std::clock();

    vector<duomenys> varg;

    paskirstymas(A,varg);
    double duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Skirstymas uztruko"<<duration<<"s"<<endl;

    start=std::clock();
    paskirstymo_isve(A,varg,pasirinkimas,p);
    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Isvedimas uztruko"<<duration<<"s"<<endl;
    }
    else if((duom_pasirinkimas == "F") || (duom_pasirinkimas == "f"))
    {

        //all=std::clock();
        //start=std::clock();
       // vector<int>rezultatai;
        //B = duom_automatinis(rezultatai,p,pasirinkimas);
        //cout<<"GENERAVIMAS UZTRUKO"<<duration<<"s"<<endl;
        duokiteRinktis(B,pasirinkimas); // B = 1000, 10000, 100000 ir tt; pasirinkimas = mediana arba galutin

        double duration =(std::clock()-start)/(double)CLOCKS_PER_SEC;

    start=std::clock();
    skaitymas(A,B);
    duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"SKAITYMAS UZTRUKO"<<duration<<"s"<<endl;
    vector<duomenys> varg;
    start=std::clock();
    //vector<duomenys> kiete;
    paskirstymas(A,varg);
    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Skirstymas uztruko"<<duration<<"s"<<endl;

    start=std::clock();
    paskirstymo_isve(A,varg,pasirinkimas,B);
    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Isvedimas uztruko"<<duration<<"s"<<endl;

    }

    cout<<":)"<<endl;

    return 0;

}
