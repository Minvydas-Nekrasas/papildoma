# Žodžių skaičialka
Tai yra C++ programa, kuri apskaičiuoja kiek kartų pasikartoja žodžiai ir išveda rezultatą į skirtingus tekstinio formato failus.

## Turinys
1. [Funkcionalumas](#funkcionalumas)
2. [Failų Struktūra](#failų-struktūra)
3. [Kompiliavimas ir Paleidimas](#kompiliavimas-ir-paleidimas)
4. [Reikalavimai](#reikalavimai)
5. [Rezultatai](#rezultatai)
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
## Reikalavimai:  
- Įdiegtas C++ kompiliatorius (pvz., GCC arba MSVC).  
- Tekstas turi būti pateiktas faile `tekstas.txt` ir `url-tekstas.txt`.

## Rezultatai:
`rezultatai.txt`:

![image](https://github.com/user-attachments/assets/013ef4be-fc50-4512-8be7-ffd95a1e97f2)

`cross_reference.txt`:

![Screenshot 2024-12-30 164517](https://github.com/user-attachments/assets/921196f8-ca54-4501-8130-08f8895a99a5)

`urls.txt`:

![Screenshot 2024-12-30 164549](https://github.com/user-attachments/assets/240a64f6-014d-4c53-83fb-ec5344641e34)
