# Žodžių skaičialka
Tai yra C++ programa, kuri apskaičiuoja kiek kartų pasikartoja žodžiai ir išveda rezultatą į skirtingus tekstinio formato failus.

## Turinys
1. [Funkcionalumas](#funkcionalumas)
2. [Failų Struktūra](#failų-struktūra)
3. [Kompiliavimas ir Paleidimas](#kompiliavimas-ir-paleidimas)
4. [Naudojimas](#naudojimas)
## Funkcionalumas
1. **Žodžių skaičiavimas**  
   Programa analizuoja failą `tekstas.txt` ir suskaičiuoja, kiek kartų kiekvienas žodis pasikartoja. Rezultatai išsaugomi faile `rezultatai.txt`.  

2. **Cross-reference lentelė**  
   Programa sukuria lentelę, kurioje nurodoma, kuriose teksto eilutėse buvo paminėti pasikartojantys žodžiai. Rezultatai išsaugomi faile `cross_reference.txt`.  

3. **URL adresų išrinkimas**  
   Programa ieško URL adresų tekstiniame faile `url-tekstas.txt` ir juos išveda į failą `urls.txt`.

## Failų Struktūra
Projektas suskirstytas į kelis failus, kad būtų lengviau tvarkyti kodą:

- main.cpp – pagrindinis programos failas.
- pagalbines.cpp ir pagalbines.h – pagalbines funkcijos cross-reference lentelės išvedimui ir url nuorodų radimui. Taip pat yra ir žodžių "išvalymo" funkcija.
- tekstas.txt ir url-tekstas.txt - tekstiniai failai sukurti programos demonstravimui.
## Kompiliavimas ir Paleidimas

>Sukompiliuoti programą galite su šia komanda:
>
>```bash
>g++ main.cpp pagalbines.cpp -o zodziai.exe
>```
>
>Paleisti programą galite su šia komanda:
>
>```bash
>./zodziai
>```
### Reikalavimai:  
- Įdiegtas C++ kompiliatorius (pvz., GCC arba MSVC).  
- Tekstas turi būti pateiktas faile `tekstas.txt` ir `url-tekstas.txt`. 
