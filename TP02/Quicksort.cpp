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
	//int simon[]={6,4,3,9,4,7,7,5,3,1,2};
	int simon[]={9,2,5,6,2,8,4,3,1};
	afficherTab(simon, 9);
	quicksort(simon, 0, 8);
	cout << endl;
	afficherTab(simon, 9);

	system("pause");
	return (0);
}
