#include "generator.h"

using namespace std;

// Funkcje do generacji liczb pierwszych

uint64_t GenerujProcent(vector <uint64_t>& lp, FILE* plik, uint64_t od, uint64_t ile)
{
    uint64_t x = 0; // liczba nowo wygenerowanych liczb pierwszych
    float before = -1; // przechowuje poprzednia wartocs procentowa
    float procent = 0; // przechowuje aktualna wartocs procentowa

    for (uint64_t i = od; i <= ile; i += 2) // Glowna petla - ineruje po wszystkich liczbach do liczby "ile" zaczynajac od "od" pomijajac liczby parzyste
    {
        bool koniec = true; // Czy skonczylo sprawdzanie danej liczby "i"
        uint64_t j = 0; // Numer iteracji pentli wewnetrznej

        while (koniec) // pentla sprwdzajaca czy liczba "i" dzieli sie przez "lp[j]"
        {
            uint64_t a = lp[j]; // "a" jest liczba przez ktora bedzie dzilona liczba "i"
            if (a * a > i) // sprawdza czy "i" jest wieksze od kwadratu "a"
            {
                // ZNALEZIONO LICZBE PIERWSZA

                x++;
                lp.push_back(i);
                koniec = false; // zakoncz petle
                fprintf(plik, "%llu", i); // zapisz do pliku
                fprintf(plik, "%s", "\n");

            }
            else if (i % a == 0) // sprawdza czy liczba "i" jest podzilna przez "a"
            {
                // NIE ZNALEZIONO LICZBY PIERWSZEJ

                koniec = false; // zakoncz petle
            }
            else if (j == lp.size()) // sprwadza czy przeszlo przez wszystkie liczby pierwsze
            {
                // ZNALEZIONO LICZBE PIERWSZA

                x++;
                lp.push_back(i);
                koniec = false; // zakozcz petle
                fprintf(plik, "%llu", i); // zapisz do pliku
                fprintf(plik, "%s", "\n");
            }
            j++;

        }

        procent = ((float)((int)(((float)i / (float)ile) * 10000))) / 100;// oblicze progres genracji

        if (before != procent) // sprwadza czy wartosc procentowa sie zmiennila
        {
            before = procent; // przypisuje aktualna wartosc procentowa do zmiennej "before"
            system("CLS");
            printf("Generuje: %4.2f %% \n", procent);
        }

    }

    return x;
}

// -------------------------------------

uint64_t GenerujDetale(vector <uint64_t>& lp, FILE* plik, uint64_t od, uint64_t ile)
{
    uint64_t x = 0; // liczba nowo wygenerowanych liczb pierwszych

    for (uint64_t i = od; i <= ile; i += 2) // Glowna petla - ineruje po wszystkich liczbach do liczby "ile" zaczynajac od "od" pomijajac liczby parzyste
    {
        bool koniec = true; // Czy skonczylo sprawdzanie danej liczby "i"
        uint64_t j = 0; // Numer iteracji pentli wewnetrznej

        while (koniec) // pentla sprwdzajaca czy liczba "i" dzieli sie przez "lp[j]"
        {
            uint64_t a = lp[j]; // "a" jest liczba przez ktora bedzie dzilona liczba "i"
            if (a * a > i) // sprawdza czy "i" jest wieksze od kwadratu "a"
            {
                // ZNALEZIONO LICZBE PIERWSZA

                x++;
                lp.push_back(i);
                koniec = false; // zakoncz petle
                printf("%llu \n", i); // wypisz na ekran
                fprintf(plik, "%llu", i); // zapisz do pliku
                fprintf(plik, "%s", "\n");

            }
            else if (i % a == 0) // sprawdza czy liczba "i" jest podzilna przez "a"
            {
                // NIE ZNALEZIONO LICZBY PIERWSZEJ

                koniec = false; // zakoncz petle
            }
            else if (j == lp.size()) // sprwadza czy przeszlo przez wszystkie liczby pierwsze
            {
                // ZNALEZIONO LICZBE PIERWSZA

                x++;
                lp.push_back(i);
                koniec = false; // zakozcz petle
                printf("%llu \n", i); // wypisz na ekran
                fprintf(plik, "%llu", i); // zapisz do pliku
                fprintf(plik, "%s", "\n");
            }
            j++;

        }
    }

    return x;
}