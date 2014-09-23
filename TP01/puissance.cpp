#include <iostream>
#include <ctime>
using namespace std;
double puiss_recur(const double a, const int n)
{
	double b;

	if (n < 0)
		return -1;
			
	if (n == 0)
		return 1;
	else if(n == 1)
		return a;
	else {
		b = puiss_recur(a, n/2);
		if(n%2 == 0)
			return b*b;
		else
			return a*b*b;
	}
}

double puiss_iter_sansastuce(const double a, const int n)
{
	double resultat = 1;
	int i;

	if (n < 0)
		return -1;
	
	for(i=0; i < n; i++)
	{
	    resultat = resultat*a;
	}
	return resultat;
}

int main()
{
	double a;
	int n;
	cout << "Entrez le nombre : ";
	cin >> a;
	cout << "Entrez son exposant : ";
	cin >> n;

	if (puiss_recur(a, n) == -1) {
		cout << "L'exposant doit être positif." << endl;
		return 1;
	}
	
	int i;
	cout << a << " puissance " << n << " = " << endl;

	clock_t temps_debut = clock();
	for (i = 0; i < 1000000000; i++) {
		puiss_iter_sansastuce(a, n);
	}
	cout << "Itératif : " << puiss_iter_sansastuce(a, n) << endl;
	cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;

	temps_debut = clock();
	for (i = 0; i < 1000000000; i++) {
		puiss_recur(a, n);
	}
	cout << "Récursif : " << puiss_recur(a, n) << endl;
	cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
}
