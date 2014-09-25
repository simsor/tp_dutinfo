#include <iostream>
#include <ctime>
using namespace std;

int pgcd_recur(const int a, const int b)
{
	if (a <= 0)
		return -1;
	
	if (a == 1 || b == 1)
		return 1;
	if(a == b)
		return a;
	else if(a > b)
		return pgcd_recur(a-b, b);
	else
		return pgcd_recur(a, b-a);
}

int pgcd_iter(const int a, const int b)
{
	int tempa=a;
	int tempb=b;

	if (a <= 0 || b <= 0)
		return -1;
	
	while((tempa != tempb) && (tempa != 1 && tempb != 1))
	{
		if (tempa > tempb)
			tempa = tempa-tempb;
		else
			tempb = tempb-tempa;
	}

	if (tempa == tempb)
		return tempa;
	else if (a==1 || b==1)
		return 1;
	else
		return -1;
}

int main()
{
	int a;
	int b;
	cout<<"Entrez le premier nombre : ";
	cin>>a;
	cout<<"Entrez le deuxième nombre : ";
	cin>>b;

	int i;
	cout << "PGCD de " << a  << " et " << b << endl;

	if (pgcd_recur(a, b) == -1) {
		cout << "Veuillez entrer des nombres positifs." << endl;
		return 1;
	}

	clock_t temps_debut = clock();
	for (i = 0; i < 10000000; i++) {
		pgcd_iter(a,b);
	}
	cout << "Itératif : " << pgcd_iter(a,b) << endl;
	cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;

	temps_debut = clock();
	for (i = 0; i < 10000000; i++) {
		pgcd_recur(a,b);
	}
	cout << "Récursif : " << pgcd_recur(a, b) << endl;
	cout << "\t" << float(clock() - temps_debut) / CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
}
