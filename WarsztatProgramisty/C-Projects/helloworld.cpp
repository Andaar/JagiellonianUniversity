#include <iostream>

using namespace std;

int PoleProstokata(int pierwszyBok, int drugiBok)
	{
		int suma = 0;
		if(pierwszyBok < 0)
		{
			pierwszyBok = pierwszyBok - pierwszyBok - pierwszyBok;
		}
		if(drugiBok < 0)
		{
			drugiBok = drugiBok - drugiBok - drugiBok;
		}
		suma = pierwszyBok * drugiBok;
		return suma;
	}
	
int main()
{
	int a = 0;
	int b = 0;
	cout << "Podaj pierwszy bok: ";
	cin >> a;
	cout << endl << "Podaj drugi bok: ";
	cin >> b;
	
	int poleP = PoleProstokata(a,b);
	if(poleP == 0)
	{
		cout << endl << "Bok nie moze byc rowny 0!" << endl;
	}
	else
	{
		cout << endl << "Pole prostokata = " << poleP;
	}
	
	return 0;
}
