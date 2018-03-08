import java.util.*;

class aWektor{
	private int[] a; // referencja do wektora
	private int maxSize; // maksymalna length wektora
	private int n; // aktualna length wektora

	//============================================= konstruktor
	public aWektor (int m) {
		maxSize = m;
		n = 0;
		a = new int[maxSize] ;
	}
	
	//==================================== wczytywanie wektora
	public void insert(int m) /*czytanie m liczb calkowitej do wektora a gdy 0<m<=maxSize*/{
		if(0<m && m<=maxSize) {
			System.out.println("Czytanie "+m+" liczb integer");
			n = m;
			for(int i=0; i<n; i++) a[i]= getInt();
		}
		else System.out.println("niepoprawna dlugosc wektora");
	}
	
	//===================================== losowanie wektora
	public void randwekt(int m, int mini, int maxi)
	// losowanie m liczb z przedzialu [mini,maxi] do wektora a
	// random()- returns a random number between 0.0 and 1.0.
	{
		if((0<m && m<=maxSize) && (mini<maxi)) {
			System.out.println ("Losowanie "+m+ " liczb z przedzialu ["+mini +","+maxi +"]");
			n = m;
			for( int i=0; i<n; i++)
			a[i]= (int)(java.lang.Math.random()*(maxi-mini)+mini) ;
		}
		else System.out.println("Niepoprawne parametry");
	}

	//====================================== wektor na ekran
	public void display(){
		System.out.println("Liczba elementow = " + n);
		System.out.println("Zawartosc wektora ") ;
		
		for (int i=0; i<n; i++ ) {
			System.out.print(a[i]+", ");
			if((i+1)%10==0) System.out.println("") ;
		}
		
		System.out.println("") ;
	}
	
	//==================================Czytanie liczby calkowitej
	public static int getInt(){
		Scanner cons = new Scanner(System.in);
		System.out.print("Podaj liczbe calkowita: ");
		
		while( !cons.hasNextInt()){
			System.out.println("Error");
			System.out.print("Podaj liczbe calkowita: ");
			cons.next();
		}
		
		int i=cons.nextInt();
		return i;
	}
	
	public void setEndElement()
	{
		if(n == maxSize) 
			System.out.println("Przekroczono maksymalna ilosd elementow wektora!");
		else
		{
			int nowyElement = getInt();
			int[] tabNew = new int[++n];
			for(int i : a)
				tabNew[i] = a[i];
			tabNew[n-1] = nowyElement;
			a = new int[n];
			a = tabNew;
		}
	}
	
	public void setEndElementAtPos()
	{
		if(n == maxSize) 
			System.out.println("Przekroczono maksymalna ilosd elementow wektora!");
		else
		{
			System.out.println("Wprowadz nr pozycji:");
			int nPos = getInt();
			if(nPos >= n+1 || nPos <= 0)
				System.out.println("Niepoprawny nr pozycji.");
			else
			{
				int[] tabNew = new int[++n];
				for(int i = 0, temp = i; i < n; i++)
				{
					if(i == nPos-1)
					{
						System.out.println("Wprowadz nowy element:");
						tabNew[i] = getInt();
					}
					else tabNew[i] = a[temp++];
				}
				a = tabNew;
			}
		}	
	}
	
	public void removeElementAtPos()
	
}

