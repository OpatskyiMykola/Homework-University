// Kr_10_05___1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rational.h"
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Enter A(a,b): ";
	cin >> a >> b;

	Pair A(a, b);

	cout << "Rez mnoj: " << A.mnojennia() << endl;

	cout << "Enter B(a,b): ";
	cin >> a >> b;

	Rational B(a, b), C(b, a);

	cout << "Vidnimannia: " << C - B << endl;;

	system("pause");
    return 0;
}

