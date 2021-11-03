# v0.1
Pirmoji užduotis

* Pirmiausia sukuriama struktura duomeny, kurioje yra studento vardas ir pavarde, pazymiai ir egzamino bei galutinis įvertinimas.
* Tada paprašoma įvesti studentų skaičių ir pasirinkti kaip bus generuojami duomenys (rankiniu ar automatiniu būdu).
1. Jeigu rankiniu budu, tuomet prašoma įvesti studento pažymius, kai baigsite įveskite 0. 
Kai įvedamas 0 programa supranta, kad baigėte vesti pažymius ir prašo įvesti egzamino įvertinimą.
2. Jeigu duomenys generuojami automatiškai, tuomet programa pasirenka atsitiktinį pažymių skaičių ir atsitiktini egzamino įvertinimą. 
* Programa suskaičiuoja galutinį įvertinimą ir randa medianą.
* Tuomet prašoma pasirinkti, ką norėsime matyti duomenų išvedime (galutinį pažymį ar medianą).
* Duomenys išvedami į ekraną.
Programa yra apsaugota nuo neteisingo simbolio arba per didelio skaičiaus įrašymo

# v0.2
Antroji užduotis
(v0.1 užduoties "patobulinimas" - nuskaitymas iš failo)

* Pirmiausia sukuriama struktura duomenys, kurioje yra studento vardas ir pavarde, pazymiai ir egzamino bei galutinis įvertinimas.
* Tuomet duomenys nuskaitomi iš failo "kursiokai.txt".
* Duomenys išvedami į failą "rez.txt".
* Apskaičiuojamas studento galutinis įvertinimas ir mediana. 
* *Kode matysite ir rikiavimą pagal vardą, tačiau jis nenaudojamas.*
*
# v0.3
Trečioji užduotis

Šioje dalyje, visos funkcijos yra išskirstytos į .h i .cpp failus.
* Pirmiausia sukuriama struktura duomenys, kurioje yra studento vardas ir pavarde, pazymiai ir egzamino bei galutinis įvertinimas.
* Leidžiama pasirinkti, kuriuo būdu gausime duomenys: nuskaitysime iš failo, generuosime automatiškai ar įvesime ranka. 
* Programa suskaičiuoja galutinį studento įvertinimą ir randa medianą.
* Tuomet prašoma pasirinkti, ką norėsime matyti duomenų išvedime (galutinį pažymį ar medianą).
* Duomenys išvedami į failą "rez1.txt".

# v0.4
Ketvirta užduotis

* Pirmiausia sukuriama struktura duomenys, kurioje yra studento vardas ir pavarde, pazymiai ir egzamino bei galutinis įvertinimas.
* Tuomet programa leidžia pasirikti, kaip gausime duomenys: generuosime automatiškai ar vesime rankiniu budu.
*Pasirinkus duomenų automatinį generavimą, prašoma pasirikti, kokio dydžio failą generuosime (1000 ar 10 000 ar 100 000 ar 1 000 000 ar 10 000 000).
* Studentai suskirstomi į dvi grupes: turintys <5 galutinį galą patenka į grupę Vargšiukai, turintys >5 galutinį balą patenka į grupę Kietekai.
* Studentu duomenų suskirstymas išvedamas į du atskirus failus ("Vargšiukai","Kietekai").

* Taip pat atliktas greičio testas (failų kūrimas, duomenų nuskaitymas iš failo, studentų rūšiavimas į dvi grupes/kategorijas, išvedimas į failą)
* 1000 duomenų;
![2021-10-15 (2)](https://user-images.githubusercontent.com/91305186/137522432-d6e958c1-d3d5-4010-b3e6-c2ee23338001.png)

* 10 000 duomenų;
![2021-10-15 (3)](https://user-images.githubusercontent.com/91305186/137522642-0ecd7205-1730-4f15-b541-dfe3cf026603.png)

* 100 000 duomenų;
![2021-10-15 (4)](https://user-images.githubusercontent.com/91305186/137522683-3505c5ce-0103-485c-b21f-29cb94ddae42.png)

* 1 000 000 duomenų;
![2021-10-15 (5)](https://user-images.githubusercontent.com/91305186/137522719-e2961ac6-220e-446b-a89b-b335b5b19fba.png)

* 10 000 000 duomenų;
![2021-10-15 (6)](https://user-images.githubusercontent.com/91305186/137522784-76fc9dff-a017-4832-993a-f872c3a405cd.png)

# v0.5
* Panaudojamas 0.4 uždavinio kodas, tačiau pakeistas konteineris. 0.5 vietoje std::vector naudojamas std::list. 
* Išmatuojami dvieju parametrų greitis: 
1. Duomenų nuskaitymas iš failų;
2. Studentų rūšiąvimas į dvi grupes (kietekaiir vargšiukai).

*Testavimo sistemos parametrai: 
***CPU: Intel(R) Core(TM) i7-8750H CPU @ 2.20GHz   2.21 GHz 
RAM: 8,00 GB
SSD: 117 GB



