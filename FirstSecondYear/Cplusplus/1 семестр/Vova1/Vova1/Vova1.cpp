#include "stdafx.h"
#include <iostream>

using namespace std;


int main() {
	

	int n;
	do  {
		cout << "Input n: ";
		cin >> n;

		if (n <= 1) {
			cout << "n must be bigger than 1" << endl;
		}
	} while (n < 2);
	
	int **a = new int *[n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			a[i][j] = -9 + rand() % 19;
		}
	}
	cout << "\nmatrix: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout  << a[i][j] << "   ";
		}
		cout << endl;
	}

	int max = a[0][0];
	int pozMax;
	int min = a[0][0];
	int pozMin;

	for (int i = 0; i<n; i++) {
		for (int j = 1; j<n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
				pozMax = i;
			}
			if (a[i][j] < min) {
				min = a[i][j];
				pozMin = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int tmp = a[pozMax][i];
		a[pozMax][i] = a[pozMin][i];
		a[pozMin][i] = tmp;
	}

	cout << "\nnew matrix: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
