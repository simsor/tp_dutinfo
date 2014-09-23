#include <iostream>
#include <ctime>
using namespace std;

int somme_iter(int n)
{
	if (n < 0) {
		cout << "Le nombre doit être positif.";
		return -1;
	}
	int resultat = 0;
	int i;
	for(i=0; i <= n; i++)
	{
		resultat = resultat + i;
	}
	return resultat;
}

int somme_recur(int n)
{
	if (n < 0) {
		cout << "Le nombre doit être positif." << endl;
		return -1;
	}
	
	if (n == 0)
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

	clock_t temps_debut = clock();
	int i;
	/*for (i = 0; i < 10000000; i++) {
		somme_recur(nbr);
		}*/

	if (somme_recur(nbr) == -1){
		return 1;
	}
		
	cout << "Recursif : " << somme_recur(nbr) << endl;
	//cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;

	temps_debut = clock();
	/*for (i = 0; i < 10000000; i++) {
		somme_iter(nbr);
		}*/

	cout << "Itératif : " << somme_iter(nbr) << endl;
	//cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}

/*

  Jeux d'essai :

  = 0
  -5
  10

 */
