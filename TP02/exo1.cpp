#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int i, j;
	int *p1, *p2;

	i=2; j=5;
	p1 = &i;
	cout << "Contenu de p1 vaut : " << *p1 << endl;
	i=i+1;
	cout << "Contenu de p1 vaut : " << *p1 << endl;
	p2 = p1;
	*p2 = *p1 + j;
	cout << "p1 vaut : " << *p1 << " / p2 vaut : " << *p2 << endl
		<< "i vaut : " << i << " et j vaut " << j << endl;

	p1=&j;
	*p1=i+j;
	cout << "p1 vaut : " << *p1 << " / p2 vaut : " << *p2 << endl
		<< "i vaut : " << i << " et j vaut : " << j << endl;
	
	system("PAUSE");
	return 0;
}