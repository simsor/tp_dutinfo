#include <iostream>
using namespace std;
double puiss_recur(const double a, const int n)
{
	double b;
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

	cout << a << " puissance " << n << " = " << endl;
	cout << "Itératif : " << puiss_iter_sansastuce(a, n) << endl;
	cout << "Récursif : " << puiss_recur(a, n) << endl;

	return 0;
}
