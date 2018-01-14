#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void WypiszTablice(int tab[], int dlugosc);
int Partition(int tab[], int poczatekTablicy, int koncowyWyraz)
{
  int ostatniWyraz = tab[koncowyWyraz];
  int wyrazMniejszyOdKoncowegoWyrazu = poczatekTablicy-1;
  int temp = 0;
  for(int i = poczatekTablicy; i < koncowyWyraz; i++)
  {
    if(tab[i] <= ostatniWyraz)
    {
      wyrazMniejszyOdKoncowegoWyrazu++;
      temp = tab[wyrazMniejszyOdKoncowegoWyrazu];
      tab[wyrazMniejszyOdKoncowegoWyrazu] = tab[i];
      tab[i] = temp;
    }
  }
  temp = ostatniWyraz;
  tab[koncowyWyraz] = tab[wyrazMniejszyOdKoncowegoWyrazu+1];
  tab[wyrazMniejszyOdKoncowegoWyrazu+1] = ostatniWyraz;
  //WypiszTablice(tab, koncowyWyraz);
  return wyrazMniejszyOdKoncowegoWyrazu+1;
}

void QuickSort(int tab[], int poczatekTablicy, int dlugoscTablicy)
{
  if(poczatekTablicy < dlugoscTablicy)
  {
    int podzielTablice = Partition(tab, poczatekTablicy, dlugoscTablicy);
    QuickSort(tab, poczatekTablicy, podzielTablice - 1);
    QuickSort(tab, podzielTablice + 1, dlugoscTablicy);
  }
}

void WypiszTablice(int tab[], int dlugosc)
{
  cout << endl;
  for (int i = 0; i < dlugosc; i++)
  {
    cout << tab[i] << " ";
  }
  cout << endl;
}

int main()
{
  srand(time(NULL));
  const int N = 10;
  int tab[N];
  for(int i = 0; i < N; i++)
  {
    tab[i] = rand() % 31;
  }

  WypiszTablice(tab, N);
  QuickSort(tab, 0, N-1);
  WypiszTablice(tab, N);

  return 0;
}
