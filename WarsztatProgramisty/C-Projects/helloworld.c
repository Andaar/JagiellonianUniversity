#include <stdio.h>
//#include <math.h>
/* https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm */
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
	printf("Podaj pierwszy bok: ");
	scanf("%i", &a);
	printf("\nPodaj pierwszy bok: ");
	scanf("%i", &b);
	int poleP = PoleProstokata(a,b);
	if(poleP == 0)
	{
		printf("Bok nie moze byc rowny 0!");
	}
	else
	{
		printf("Pole prostokata = %d",poleP);
	}

	/*printf("Hello World!\n");*/
	
	return 0;
}

