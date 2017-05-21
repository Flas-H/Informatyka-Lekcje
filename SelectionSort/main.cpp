#include <iostream>
#include <cstdlib>
#include <ctime>

void cocktailSort();
void hybridSort(int lewy, int prawy);

const int rozmiar = 10;
int tab[rozmiar];

int main()
{

	srand(time(NULL));
	for(int& pozycja : tab){
		pozycja = rand() % 11;
	}
		
	for(int pozycja : tab){
		std::cout << pozycja << " ";
	}
	std::cout << std::endl;
	
	hybridSort(0, rozmiar - 1);
	
	for(int pozycja : tab){
		std::cout << pozycja << "s ";
	}
	std::cout << std::endl;

}

void cocktailSort(){
	int min;
	int max;
	int bufor;
	
	for(int i = 0; i < rozmiar / 2; i++){
		min = i;
		max = rozmiar - i - 1;
		for(int j = i + 1; j < rozmiar - i; j++){
			if(tab[j] < tab[min]) min = j;
			else if(tab[j] > tab[max]) max = j;
		}
		bufor = tab[i];
		tab[i] = tab[min];
		tab[min] = bufor;
		
		bufor = tab[rozmiar - i - 1];
		tab[rozmiar - i - 1] = tab[max];
		tab[max] = bufor;
	}
}

void hybridSort(int lewy, int prawy){
	/*if(prawy - lewy < 10) cocktailSort();
	else*/ if(lewy < prawy){
		int indexerLewy = lewy;
		int indexerPrawy = prawy;
		int srodek = (lewy + prawy) / 2;
		
		while(indexerLewy < indexerPrawy){
			if(tab[indexerLewy] <= tab[srodek]) indexerLewy++;
			else if(tab[indexerPrawy] >= tab[srodek]) indexerPrawy--;
			else{				
				int bufor = tab[indexerLewy];
				tab[indexerLewy] = tab[indexerPrawy];
				tab[indexerPrawy] = bufor;
			}
		}
		
		if(indexerLewy > lewy) hybridSort(lewy, indexerLewy);
		if(indexerPrawy < prawy) hybridSort(indexerPrawy, prawy);
		
	}
}