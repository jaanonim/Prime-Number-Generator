#include <windows.h>
#include "loader.h"

using namespace std;

// Czytanie pliku

// --------- Liczy licze lini w pliku -----------
uint64_t getNumberOfLines(FILE* fp, char* name)
{
    uint64_t countLines = 1;
    int i;

    system("CLS");
    printf("Obliczam rozmiar pliku ... \n");

    while ((i = fgetc(fp)) != EOF)
    {
        if (i == '\n')
            countLines++;
    }
    fclose(fp); // zamyka plik
    fp = fopen(name, "r"); // otwiera pik do odczytu
    return countLines;
}

// -------- Zczytuje dane z pliku ---------------
uint64_t getTxt(vector <uint64_t>& lp, FILE* plik, char* name)
{

    uint64_t Nr_lini = 1; // liczba zczytanich linijek

    if (plik == NULL) // sprawdza czy plik istnieje
    {
        // PLIK  NIE ISNIEJE

        system("CLS");

        printf("Nie da sie otworzyc pliku ! \n");
        printf("Generuje bez wczytywania pliku ! \n");

    }
    else
    {
        // PLIK ISTNIEJE

        uint64_t liczba_lini = getNumberOfLines(plik,name); //sprwadza ile lini ma plik

        system("CLS");
        printf("Zanalezionio %llu linijek do wszczytania.\n", liczba_lini);
        Sleep(1000);

        int a = 1; // zmienna do sprawdzania czy jest to koniec pliku
        int procent = 0; // przechowuje aktualna wartocs procentowa
        int before = -1; // przechowuje poprzednia wartocs procentowa

        while (a != EOF) // dopoki nie ma konca pliku
        {
            procent = (int)(((float)Nr_lini / (float)liczba_lini) * 100);// oblicze progres wczytywania

            if (before != procent) // sprwadza czy wartosc procentowa sie zmiennila
            {
                before = procent; // przypisuje aktualna wartosc procentowa do zmiennej "before"
                system("CLS");
                printf("Wczytywanie: %d %% \n", procent);
            }

            uint64_t bufor; // bufor od przechowania warto�ci zczytaniej z pliku
            a = fscanf(plik, "%llu", &bufor); // zczytaj pilku
            lp.push_back(bufor); // dodaj do listy lp
            Nr_lini++;
        }
    }
    //lp[Nr_lini - 1] = NULL;
    Sleep(500);
    system("CLS");

    fclose(plik); // zamyka plik
    plik = fopen(name, "a+"); // otwiera plik do zapisu


    return Nr_lini;
}
