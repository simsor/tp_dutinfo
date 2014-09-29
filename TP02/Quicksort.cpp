#include <iostream>
#include <stdlib.h>
using namespace std;

void quicksort(int tab[],const int debut, const int fin)
{
	int a;
	int b;
	int pivot;
	int temp;

	if ((fin-debut)+1 <= 1)
		return;

	a = debut;
	b = fin;
	pivot = tab[(fin+debut)/2];
	while (a<=b)
	{
		while (tab[a]<pivot)
			a++;
		while (tab[b]>pivot)
			b--;
		if (a<=b)
		{
			temp=tab[a];
			tab[a]=tab[b];
			tab[b]=temp;
			a++;
			b--;
		}
	}
	quicksort(tab, debut, b);
	quicksort(tab, a, fin);
}

void afficherTab(int tab[], int taille)
{
	int compt;
	for (compt=0; compt<taille; compt++)
		cout << tab[compt] << "  ";
}

int main()
{
	int tableau[]={4,6,2,3,9,8,1};
	afficherTab(tableau, 7);
	quicksort(tableau, 0, 6);
	cout << endl;
	afficherTab(tableau, 7);
	cout << endl;
	return (0);
}
