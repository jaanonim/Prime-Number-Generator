#include <vector>
#include <windows.h>
#include <time.h>
#include <cstdio>
#include "generator.h"
#include "loader.h"

using namespace std;


int main()
{
    vector <uint64_t> lp; // przechowuje liczby pierwsze
    uint64_t od; // liczba od ktorej beda generowane liczby pierwsze
    uint64_t ile; // liczba do ktorej liczby pierwsze beda generowne
    FILE * plik; // tworzy zmienne dla pliku

    char* name = "liczby_pierwsze.txt"; // nazwa pilku
    int tryb = 1; // zmienna przechowujaca wybrany tryb
    
    // -------------------------------

    plik = fopen(name,"r"); // otwiera pik do odczytu

    lp.clear();

    uint64_t d = getTxt(lp,plik,name); // zczytuje dane z pliku
    od = lp[d-2]+2; // ustawienie ostatniej wszctaniej wartosci +2 (nastepna nieprzysta liczba) jakow wartosc od ktorej ma zaczynac generowanie

    // -------------------------------

    system("CLS");
    printf("DANE: \n");
    printf("Ostatnia liczba: %llu \n", od-1);
    printf("Dlugosc: %llu \n",lp.size());
    printf("Pojemnosc: %llu \n",lp.capacity());
    printf("Maxymalna dlugosc: %llu \n\n",lp.max_size());
    system("pause");

    system("CLS");
    printf("Wybierz tryb generacji: \n  1) Dokladny [domyslny] \n  2) Procentowy [szybszy] \n");
    scanf("%d", &tryb);

    system("CLS");
    printf("Podaj liczbe do ktorej beda sprawdzenie wszystkie liczby: \n");
    scanf("%llu",&ile);

    system("CLS");

    // -------------------------------

    printf("Generuje...\n");
    Sleep(1000);
    system("CLS");

    long double wynik; // czas generacji
    clock_t start, stop; // timery
    uint64_t x = 0; // liczba nowo wygenerowanych liczb pierwszych

    start = clock(); // Start timera

    if (tryb == 2) // Wybiera tryb
    {
        x=GenerujProcent(lp, plik, od, ile); // generuje liczby pierwsze wyswietlajac procent
    }
    else 
    {
        x=GenerujDetale(lp, plik, od, ile); // generuje liczby pierwsze wyswietlacjac ilczby
    }

    stop=clock(); // Zatrzymanie zagaru
    wynik = (long double)(stop-start) / CLOCKS_PER_SEC; // obliczenie czasu generacji

    // -------------------------------

    system("CLS");
    printf("Wygenerowano %llu liczb pierwszych, z czego %llu nowych, W czasie: %lf s. \n", lp.size(), x, wynik); // wypisanie na ekranie wyniku generacji

    fclose(plik); // zamkniecie pliku :-)
    system("pause");
    return 0;
}
