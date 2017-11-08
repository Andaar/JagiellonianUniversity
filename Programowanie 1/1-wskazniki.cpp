/**
    1-wskazniki.cpp
    Zadanie: Napisz następujące programy przy użyciu arytmetyki
    wskaźników - nie jest dozwolone indeksowanie tablic.
    Przez zakres [b,e) rozumiemy parę wskaźników, z których b
    pokazuje na początek danych, a e pokazuje na element "następny za ostatnim".

    + wypisanie elementów zakresu [b,e) na standardowe wyjście;
    + obliczenie sumy elementów zakresu [b,e);
    + wyszukiwanie największej liczby w zakresie [b,e);
    + odwracanie kolejności elementów zakresu [b,e);
    + scalanie dwóch posortowanych zakresów w trzeci (również posortowany).

    @author:  Igor Kozub
*/

#include <iostream>
#include <ctime>

using namespace std;

void SortowanieBabelkowe(int* tablica, int dlugoscTablicy)
{
  int temp = 0;
  for(int i = 0; i < dlugoscTablicy-1; i++)
  {
    for(int j = 0; j < dlugoscTablicy-1; j++)
    {
      if(*(tablica+j) > *(tablica+j+1))
      {
        temp = *(tablica+j);
        *(tablica+j) = *(tablica+j+1);
        *(tablica+j+1) = temp;
      }
    }
  }
}

void WpisywanieWartosciDoPrzedzialu(int* tablicaWejsciowa, int* przedzial,
  int poczatekPrzedzialu, int dlugoscPrzedzialu)
  {
    for(int *tablica = tablicaWejsciowa+poczatekPrzedzialu-1,
      i = 0; i < dlugoscPrzedzialu; i++)
      {
        *przedzial++ = *tablica++;
      }
  }

void PolaczeniePrzedzialow(int* pierwszy, int* drugi, int* zlaczenie,
  int dlugoscPierwszegoPrzedzialu, int dlugoscDrugiegoPrzedzialu,
  int dlugoscPolaczonychPrzedzialow)
  {
    for(int i = 0, dlugoscPierwszego = 0, dlugoscDrugiego = 0; i <= dlugoscPolaczonychPrzedzialow; i++)
      {
        if(dlugoscPierwszego < dlugoscPierwszegoPrzedzialu &&
        dlugoscDrugiego < dlugoscDrugiegoPrzedzialu)
        {
          if(*pierwszy < *drugi)
          {
            *zlaczenie++ = *pierwszy++;
            dlugoscPierwszego++;
          }
          else if(*drugi < *pierwszy)
          {
            *zlaczenie++ = *drugi++;
            dlugoscDrugiego++;
          }
          else
          {
            *zlaczenie++ = *pierwszy++;
            *zlaczenie++ = *drugi++;
            dlugoscPierwszego++;
            dlugoscDrugiego++;
          }
        }
        else if(dlugoscPierwszego == dlugoscPierwszegoPrzedzialu)
        {
          *zlaczenie++ = *drugi++;
        }
        else
        {
          *zlaczenie++ = *pierwszy++;
        }
      }
  }

void WyswietlanieTablicy(int* tablica, int dlugoscTablicy)
{
  for(int i = 0; i < dlugoscTablicy; i++)
  {
    cout << "[" << i+1 << "] = " << *tablica++ << endl;
  }
}
void ZwracaniePosortowanegoZakresu(int* pierwszaTablica,
  int poczatekPrzedzialuPierwszego, int koniecPrzedzialuPierwszego,
  int* drugaTablica, int poczatekPrzedzialuDrugiego, int koniecPrzedzialuDrugiego)
  {
    // deklarowanie dlugosci przedzialow, aby potem utworzyc 3 tablice
    int dlugoscPierwszegoPrzedzialu =
    koniecPrzedzialuPierwszego - poczatekPrzedzialuPierwszego+1;
    int dlugoscDrugiegoPrzedzialu =
    koniecPrzedzialuDrugiego - poczatekPrzedzialuDrugiego+1;
    int dlugoscPolaczonychPrzedzialow =
    dlugoscPierwszegoPrzedzialu + dlugoscDrugiegoPrzedzialu;

    int przedzialPierwszy[dlugoscPierwszegoPrzedzialu];
    int przedzialDrugi[dlugoscDrugiegoPrzedzialu];
    int* wskaznikPrzedzialuPierwszego = przedzialPierwszy;
    int* wskaznikPrzedzialuDrugiego = przedzialDrugi;
    WpisywanieWartosciDoPrzedzialu(pierwszaTablica, wskaznikPrzedzialuPierwszego,
       poczatekPrzedzialuPierwszego, dlugoscPierwszegoPrzedzialu);
    WpisywanieWartosciDoPrzedzialu(drugaTablica, wskaznikPrzedzialuDrugiego,
          poczatekPrzedzialuDrugiego, dlugoscDrugiegoPrzedzialu);
    SortowanieBabelkowe(wskaznikPrzedzialuPierwszego, dlugoscPierwszegoPrzedzialu);
    SortowanieBabelkowe(wskaznikPrzedzialuDrugiego, dlugoscDrugiegoPrzedzialu);

    int polaczonePrzedzialy[dlugoscPolaczonychPrzedzialow];
    int* wskaznikPolaczonychPrzedzialow = polaczonePrzedzialy;

    PolaczeniePrzedzialow(wskaznikPrzedzialuPierwszego, wskaznikPrzedzialuDrugiego,
      wskaznikPolaczonychPrzedzialow, dlugoscPierwszegoPrzedzialu,
      dlugoscDrugiegoPrzedzialu, dlugoscPolaczonychPrzedzialow);
    WyswietlanieTablicy(wskaznikPolaczonychPrzedzialow, dlugoscPolaczonychPrzedzialow);
  }
int main()
{
  int N = 10;
  int tab[N];
  for(int i = 0; i < N; i++)
  {
    tab[i] = i+1;
  }

  // [b,e)
  // [3,10)
  int b = 3;
  int e = 7;

  int* wskaznikTablicy = tab;
  int* poczatekPrzedzialuTablicy = wskaznikTablicy+b-1; // b = tab[2]
  int* koniecPrzedzialuTablicy = wskaznikTablicy+e-1; // e = tab[9]

  // wypisywanie elementów tablicy
  cout << endl <<
  "1.1 Wypisanie elementów zakresu [b,e) na standardowe wyjście:" << endl;
  for(int*i = poczatekPrzedzialuTablicy; i != koniecPrzedzialuTablicy;)
  {
    cout << *i++ << endl;
  }

  // obliczenie sumy zakresu [b,e)
  cout << endl <<
  "1.2 Obliczenie sumy elementów zakresu [b,e):" << endl;
  int suma = 0;
  for(int* i = poczatekPrzedzialuTablicy; i != koniecPrzedzialuTablicy;)
  {
    suma += *i++;
  }
  cout << "Suma zakresu [b,e) = " << suma << endl;

  // wyszukiwanie najwiekszej liczby w przedziale [b,e)
  cout << endl <<
  "1.3 Wyszukiwanie największej liczby w zakresie [b,e):" << endl;
  int wartoscMaxymalnaPrzedzialu = *poczatekPrzedzialuTablicy;
  for(int* i = poczatekPrzedzialuTablicy; i != koniecPrzedzialuTablicy;)
  {
    if(wartoscMaxymalnaPrzedzialu < *i)
    {
      wartoscMaxymalnaPrzedzialu = *i;
    }
    i++;
  }
  cout << "Wartosc najwieksza przedziału [b,e) = " << wartoscMaxymalnaPrzedzialu
    << endl;

  // odwracanie przedziału zakresu [b,e)
  cout << endl <<
  "1.4 Odwracanie kolejności elementów zakresu [b,e):" << endl;
  int temp = 0;
  for(int *x = tab, i = 0, poczatekCzyliB = b-1, konieczCzyliE = e - 2;
    i < (e-b)/2;i++)
    {
      temp = *(x+(poczatekCzyliB));
      *(x+poczatekCzyliB++) = *(x+(konieczCzyliE));
      *(x+konieczCzyliE--) = temp;
    }
  for(int*i = poczatekPrzedzialuTablicy; i != koniecPrzedzialuTablicy;)
  {
    cout << *i++ << endl;
  }

  // scalanie dwóch posortowanych przedziałów w trzeci, który jest
  // również posortowany
  cout << endl <<
  "1.5 Scalanie dwóch posortowanych zakresów w trzeci (również posortowany):" << endl;

  srand(time(NULL));

  int X = 8;
  int Y = 11;
  int tabelkaA[X];
  int tabelkaB[Y];

  for(int *tabela = tabelkaA, i = 0; i < X; i++)
  {
    *tabela++ = rand() % 100;
  }
  for(int *tabela = tabelkaB, i = 0; i < Y; i++)
  {
    *tabela++ = rand() % 100;
  }

  ZwracaniePosortowanegoZakresu(tabelkaA, 5, 8, tabelkaB, 3, 9);

  return 0;
}
