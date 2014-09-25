#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int tab[5];
	int *p1, *p2;
	char str[20];
	char *c;

	tab[0] = 5;
	cout << "tab[2] vaut : " << tab[2] << endl;
	p1 = tab + 1;
	*p1 = 10;
//	*p2 = 20;
	p2 = p1;
	cout << "p1 vaut : " << *p1 << " / p2 vaut : " << *p2 << endl;
	//tab = p1 + 1;
	//c = tab + 3;
	gets(str);
	c = str + 2;
	c = c+1;
	cout << "caractère : " << *(c+1) << endl;
	gets(c);
	cout << "Chaine : " << str << endl; 
	system("pause");
	return 0;
}