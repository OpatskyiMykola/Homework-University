#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include  <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

//повертає матрицю 1
float** getMatrix(int n, float *arrX) {    
	float **mat = new float *[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new float[n];
		for (int j = 0; j < n; j++) {
			mat[i][j] = pow(arrX[j], i);
		}
	}
	return mat;
	delete []mat;
}      
//печетати в файл матрицю 1
void Print_Matrix1(float** matr, int n, ofstream& output) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			output << setw(4) << matr[i][j];
		}
		output << endl;
	}
	for (int i = 0; i < n+1; i++) {
		output << "____";
	}
	output << endl;
}
//повертає позицію максимального
int getPozMax(float** matr, int n, int m) {
	float  max = matr[0][0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (matr[i][i] > max) {
			max = matr[i][i];
			p = i;
		}
	}

	
	return p;
}
//печатає 2у матрицю
void Print_Matrix2(float** matr, int n, ofstream& output) {
	for (int i = 0; i < n; i++) {         //печать
		for (int j = 0; j < n; j++) {
			output << setw(4) << matr[i][j];
		}
		output << endl;
	}
	for (int i = 0; i < n + 1; i++) {
		output << "____";
	}
	output << endl;


}

int main() {
	ofstream output;
	output.open("out.txt");
	int n, m;
	do {
		cout << "Enter n: ";	
		cin >> n;     // бере n
	} while (n < 2);
	
	float *arrX = new float [n];
	for (int i = 0; i < n; i++) {
		cout << "X" << i + 1 << ": "; cin >> arrX[i];    //Бере масив X
	}

	float **matr = getMatrix(n, arrX);        //Бере матрицю 1

	Print_Matrix1(matr, n, output);
	do {
		cout << "Enter m: ";    cin >> m;       //бере m
	} while (m<1 || m>n);

	int p = getPozMax(matr, n, m);
	float **tmp_mat = new float *[n];    //tmp_matrx
	for (int i = 0; i < n; i++) {
		tmp_mat[i] = new float[n];
	}

	for (int i = 0; i < n; i++) {         //сорт
		for (int j = 0; j < n; j++) {
			tmp_mat[m - 1][j] = matr[p][j];
			matr[p][j] = matr[m - 1][j];
			matr[m - 1][j] = tmp_mat[m - 1][j];
		}
	}

	Print_Matrix2(matr, n, output);


	return 0;
}