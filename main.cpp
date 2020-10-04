#include <vector>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <string>
#include <cstdio>


using namespace std;

vector <uint64_t> lp; // przechowuje liczby pierwsze
uint64_t x = 0; // liczba nowo wygenerowanych liczb pierwszych
uint64_t od; // liczba od ktorej beda generowane liczby pierwsze
uint64_t ile; // liczba do ktorej liczby pierwsze beda generowne
long double wynik; // czas generacji
clock_t start,stop; // timery
char* name = "liczby_pierwsze.txt"; // nazwa pilku

// -------------------------------------
// Czytanie pliku
// -------------------------------------

// --------- Liczy licze lini w pliku -----------
uint64_t getNumberOfLines(FILE *fp)
{
    uint64_t countLines = 1;
    int i;

    system("CLS");
    printf("Obliczam rozmiar pliku ... \n");

    while((i=fgetc(fp))!=EOF)
    {
        if (i == '\n')
            countLines++;
    }
    fclose(fp); // zamyka plik
    fp = fopen(name,"r"); // otwiera pik do odczytu
    return countLines;
}

// -------- Zczytuje dane z pliku ---------------
uint64_t getTxt(vector <uint64_t> &lp,FILE *plik)
{

    uint64_t Nr_lini=1; // liczba zczytanich linijek

    if(plik==NULL) // sprawdza czy plik istnieje
    {
		// PLIK  NIE ISNIEJE

        system("CLS");

        printf("Nie da sie otworzyc pliku ! \n");
        printf("Generuje bez wczytywania pliku ! \n");

    }
    else
    {
		// PLIK ISTNIEJE

        uint64_t liczba_lini = getNumberOfLines(plik); //sprwadza ile lini ma plik

        system("CLS");
        printf("Zanalezionio %llu linijek do wszczytania.\n", liczba_lini);
        Sleep(1000);

        int a=1; // zmienna do sprawdzania czy jest to koniec pliku
        int procent = 0; // przechowuje aktualna wartocs procentowa
        int before = -1; // przechowuje poprzednia wartocs procentowa

        while(a!=EOF) // dopoki nie ma konca pliku
        {
            procent = (int)(((float)Nr_lini/(float)liczba_lini)*100);// oblicze progres wczytywania

            if(before!=procent) // sprwadza czy wartosc procentowa sie zmiennila
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
    lp[Nr_lini-1]=NULL;
    Sleep(500);
    system("CLS");

    fclose(plik); // zamyka plik
    plik = fopen(name,"a+"); // otwiera plik do zapisu


    return Nr_lini;
}
// -------------------------------------

// -------------------------------------
// Funkcje do generacji liczb pierwszych
// -------------------------------------
void GenerujProcent(vector <uint64_t>& lp, FILE* plik, uint64_t od, uint64_t ile)
{
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
}


void GenerujDetale(vector <uint64_t>& lp, FILE* plik, uint64_t od, uint64_t ile)
{
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
                printf("%llu \n",i); // wypisz na ekran
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
                printf("%llu \n",i); // wypisz na ekran
                fprintf(plik, "%llu", i); // zapisz do pliku
                fprintf(plik, "%s", "\n");
            }
            j++;

        }
    }
}
// -------------------------------------

int main()
{
    int tryb = 1; // zmienna przechowujaca wybrany tryb
    FILE * plik; // tworzy zmienne dla pliku
    plik = fopen(name,"r"); // otwiera pik do odczytu

    lp.clear();

    uint64_t d = getTxt(lp,plik); // zczytuje dane z pliku
    od = lp[d-2]+1; // ustawienie ostatniej wszctaniej wartosci +1 jakow wartosc od ktorej ma zaczynac generowanie

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

    printf("Generuje...\n");
    Sleep(1000);
    system("CLS");

    if(od==3)
    {
        printf("2");
    }

    start = clock(); // Start timera

    if (tryb == 2) // Wybiera tryb
    {
        GenerujProcent(lp, plik, od, ile); // generuje liczby pierwsze wyswietlajac procent
    }
    else 
    {
        GenerujDetale(lp, plik, od, ile); // generuje liczby pierwsze wyswietlacjac ilczby
    }

    stop=clock(); // Zatrzymanie zagaru
    wynik = (long double)(stop-start) / CLOCKS_PER_SEC; // obliczenie czasu generacji

    system("CLS");
    printf("Wygenerowano %llu liczb pierwszych, z czego %llu nowych, W czasie: %lf s. \n", lp.size(), x, wynik); // wypisanie na ekranie wyniku generacji

    fclose(plik); // zamkniecie pliku :-)
    system("pause");
    return 0;
}
