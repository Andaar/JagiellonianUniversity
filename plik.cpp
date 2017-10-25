#include <iostream>

using namespace std;

void MinimumMaksimum(int tab[], int length)
{
	int max = 0;
	int min = 0;
	for(int i = 0; i < length; i++)
	{
		if(tab[i] < min)
		{
			min = tab[i];
		}
		else if(tab[i] > max)
		{
			max = tab[i];
		}
		cout << i << endl;
	}
	cout << "Wartosc maksymalna: " << max << endl;
	cout << "Wartosc minimalna: " << min << endl;
}

int main()
{
	int tab[12] = {-1,0,1,2,3,4,5,6,7,8,9,10};
	int dlugoscTablicy = sizeof(tab)/sizeof(tab[0]);
	MinimumMaksimum(tab, dlugoscTablicy);
	return 0;
}
