#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ZnajdzMinimum(int poczatek, int tab[], int dlugoscTablicy)
{
  int minID = poczatek;
  for(int i = poczatek + 1; i < dlugoscTablicy; i++)
  {
    if(tab[minID] > tab[i])
    {
      minID = i;
    }
  }
  return minID;
}
int main()
{
  srand(time(NULL));
  int dlugoscTablicy = 10;
  int tab[dlugoscTablicy];
  for(int i = 0; i < dlugoscTablicy; i++)
  {
    tab[i] = rand() % 100;
    cout << tab[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < dlugoscTablicy; i++)
  {
    int temp = tab[i];
    int minID = ZnajdzMinimum(i, tab, dlugoscTablicy);
    tab[i] = tab[minID];
    tab[minID] = temp;
  }

  for(int i = 0; i < dlugoscTablicy; i++)
  {
    cout << tab[i] << " ";
  }
  return 0;
}
