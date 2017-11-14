#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
  const int dlugoscTablicy = 10;
  int tab[dlugoscTablicy];
  for(int i = 0; i < dlugoscTablicy; i++)
  {
    tab[i] = rand() % 100;
    cout << tab[i] << " ";
  }
  cout << endl;

  int dlugoscTablicyJ = dlugoscTablicy;
  for(int i = 0; i < dlugoscTablicyJ; i++)
  {
    int minID = i;
    int maxID = i;
    int minimum;
    int maximum = tab[dlugoscTablicyJ-1];
    // znajdywanie minimum i maksimum
    for(int j = i + 1; j < dlugoscTablicyJ; j++)
    {
      if(tab[minID] > tab[j])
      {
        minID = j;
      }
      else if(tab[maxID] <= tab[j])
      {
        maxID = j;
      }
    }
    tab[dlugoscTablicyJ-1] = tab[maxID];
    tab[maxID] = maximum;
    minimum = tab[i];
    if(minID != dlugoscTablicyJ-1 )
    {
      tab[i] = tab[minID];
      tab[minID] = minimum;
    }
    else if(maxID != i && minID == dlugoscTablicyJ-1)
    {
      tab[i] = tab[maxID];
      tab[maxID] = minimum;

    }
    dlugoscTablicyJ--;
    //WypiszTablice(tab,dlugoscTablicy);
  }

  WypiszTablice(tab,dlugoscTablicy);
  return 0;
}
