#include <stdio.h>

int main()
{
  int iloscWierszy = 3;
  int liczbaSpacji = iloscWierszy - 1;
  int iloscGwiazdek = 1;
  for(int i = 0; i < iloscWierszy; i++)
  {
      for(int j = 0; j < liczbaSpacji; j++)
      {
          printf(" ");
      }
      for(int j = 0; j < iloscGwiazdek; j++)
      {
        printf("*");
      }
      iloscGwiazdek += 2;
      liczbaSpacji--;
      printf("\n");
  }

  return 0;
}
