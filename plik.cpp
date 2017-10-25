#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void MinimumMaksimum(int tab[], int length)
{
	int max = tab[0]; 
	int min = tab[0];
	for(int i = 1; i < length; i++)
	{
		if(tab[i] < min)
		{
			min = tab[i];
		}
		else if(tab[i] > max)
		{
			max = tab[i];
		}
	}
	cout << "Wartosc maksymalna: " << max << endl;
	cout << "Wartosc minimalna: " << min << endl;
}

void BubbleSort(int tab[], int length)
{
	int temporary = 0;
	for(int j = 0; j < length - 1; j++)
	{
		for(int i = 0; i < length -1; i++)
		{
			
			if(tab[i] > tab[i+1])
			{
				temporary = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = temporary;
			}
		}
	}
}
int main()
{
	int dlugoscTablicy = 20;
	int tab[dlugoscTablicy];
	srand(time(0));
	for(int i = 0; i < dlugoscTablicy; i++)
	{
		tab[i] = rand()%100;
	}
	for (int i = 0; i < dlugoscTablicy; i++)
	{
		cout << tab[i] << ", ";
	}
	cout << endl;
	BubbleSort(tab,dlugoscTablicy);
	
	for (int i = 0; i < dlugoscTablicy; i++)
	{
		cout << tab[i] << ", ";
	}
	cout << endl;
	MinimumMaksimum(tab, dlugoscTablicy);
	return 0;
}
