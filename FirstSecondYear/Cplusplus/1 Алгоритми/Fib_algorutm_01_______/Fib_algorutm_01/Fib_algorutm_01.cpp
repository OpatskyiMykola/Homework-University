//zdelal in the morning of 17.03
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

bool check(int a){
	while (a > 10) {
		a /= 10;
	}
	return a % 2 == 0 ? true : false;
}
int size(int x) {
	x = x;
	int size1 = 1;
	while ((int)x / 10 >= 1) {
		x /= 10;
		size1++;
	}
	return size1;
}
int main()
{
	int a = 1, b = 1, x = 0;
	cout << "Enter size: ";
	int n, count = 0;
	cin >> n;
	int lol = n;
	n = pow(10, n) - 1;
	while (x<n){
		x = a + b;
		a = b;
		b = x;
		if(lol == size(x))
			if (check(x)) { 
				cout << x << " "; 
				count++;
			}
	}
	cout << endl << "rez: " << count << endl;
	system("pause");
    return 0;
}

