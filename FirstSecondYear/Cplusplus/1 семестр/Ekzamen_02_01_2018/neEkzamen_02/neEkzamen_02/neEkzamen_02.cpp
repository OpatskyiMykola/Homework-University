#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int** getMatrix(int n) {
	int **matr = new int *[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
		for (int j = 0; j < 2; j++) {
			matr[i][j] = -9 + rand() % 19;
		}
	}
	return matr;
	delete[]matr;
}

void dodav(int** matr, int n) {
	int *sum = new int[n];

	for (int i = 0; i < n; i++) {
		sum[i] = matr[0][i] + matr[1][i];
	}
	cout << "\nsum: ";
	for (int i = 0; i < n; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
}

void mnojNaSkal(int** matr, int n, int skal) {

}
void meinFync(int Opr, int** matr, int n, int skal) {
	if(Opr == 1) 	dodav(matr, n); 
	if (Opr == 2)    mnojNaSkal(matr, n, skal);
	if(Opr == 3)    dodav(matr, n);
}


int main()
{
	int n;
	cout << "n: ";
	cin >> n;

	int** matr = getMatrix(n); 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	int Opr;
	cout << "Enter Operacion (1 - dod || 2 - * na skal || 3 - skal dob): ";
	cin >> Opr;

	int skal;
	if (Opr == 2) {
		cout << "Enter const: ";
		cin >> skal;
	}

	meinFync(Opr, matr, n, skal);

    return 0;
}

