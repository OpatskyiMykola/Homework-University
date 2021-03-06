#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>

const int n = 1000;
int countOfmax[123];

using namespace std;

void countSort(char **arr, int d)
{
	char output[n][3];

	int count[122 + 1];

	for (int i = 0; i < 123; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int k = arr[i][d];
		count[k]++;
		countOfmax[k]++;
	}

	for (int i = 97; i <= 122; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int k = arr[i][d];
		for (int j = 0; j < 3; j++) {
			output[count[k] - 1][j] = arr[i][j];
		}
		count[k]--;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = output[i][j];
		}
	}
	cout << "iteracii: " << arr[0][0] << arr[0][1] << arr[0][2] << endl;
}

void RadixSort(char**arr) {
	for (int i = 2; i >= 0; i--) {
		countSort(arr, i);
	}
}

void printParol(char**arr) {
	char *s = new char[7];
	int max = countOfmax[97], index = 97;
	for (int i = 98; i <= 122; i++) {
		if (countOfmax[i] > max) {
			max = countOfmax[i];
			index = i;
		}
	}

	cout << "\nPapol for laba: ";
	for (int i = 0; i < 7; i++) {
		if (i < 3) {
			cout<<  arr[0][i];
		}
		else if (i > 3) {
			cout <<  arr[n - 1][i - 4];
		}
		else {
			cout <<  char(index);
		}
	}
	cout << endl;
}

int main()
{
	ifstream in("text.txt");

	char**arr = new char*[n];           //зчитування бази з файлу
	for (int i = 0; i < n; i++) {
		arr[i] = new char[3];
		in >> arr[i];
	}

	RadixSort(arr);
	printParol(arr);

	system("pause");
    return 0;
}


