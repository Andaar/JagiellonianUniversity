#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

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

  for(int i = 1; i < dlugoscTablicy; i++)
  {
    int sprawdzanaWartosc = tab[i];
    int j = i - 1;
    while(j >= 0 && tab[j] > sprawdzanaWartosc)
    {
      tab[j+1] = tab[j];
      j--;
    }
    tab[j+1] = sprawdzanaWartosc;
  }

  for(int i = 0; i < dlugoscTablicy; i++)
  {
    cout << tab[i] << " ";
  }
  cout << endl;

  return 0;
}
