#include <iostream>
using namespace std;

int somme_iter(int n)
{
	if (n < 0) {
		cout << "Le nombre doit être positif.";
		return -1;
	}
	int resultat = 0;
	int i;
	for(i=0; i<=n; i++)
	{
		resultat = resultat + i;
	}
	return resultat;
}

int somme_recur(int n)
{
	if (n < 0) {
		cout << "Le nombre doit être positif.";
		return -1;
	}
	
	if (n==0)
		return 0;
	else
		return n + somme_recur(n-1);
}

int main()
{
	int nbr;
	cout << "Entrez un nombre : ";
	cin >> nbr;
	cout << "Somme des entiers de 1 à " << nbr << " : " << endl;
	cout << "Recursif : " << somme_recur(nbr) << endl;
	cout << "Itératif : " << somme_iter(nbr) << endl;

	return 0;
}

/*

  Jeux d'essai :

  = 0
  -5
  10

 */
