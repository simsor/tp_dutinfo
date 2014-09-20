#include <iostream>
using namespace std;

int pgcd_recur(const int a, const int b)
{
	if (a == 0)
		cout<<"Erreur";
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

	cout << "PGCD de " << a  << " et " << b << endl;
	cout << "Itératif : " << pgcd_iter(a,b) << endl;
	cout << "Récursif : " << pgcd_recur(a, b) << endl;
	return 0;
}
