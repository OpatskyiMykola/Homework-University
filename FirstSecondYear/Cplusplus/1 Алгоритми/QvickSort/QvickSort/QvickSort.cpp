#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

long* quickSort(long arr[], long left, long right) {

	long i = left, j = right;
	long tmp;
	int pivot = arr[right];
	
	/* partition */

	while (i <= j) {

		while (arr[i] < pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}

	};

	/* recursion */

	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);

	return arr;
}


int main() {
	int n;
	cout << "Enter n: "; cin >> n;

	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	arr = quickSort(arr, 0, n - 1);

	for (long i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
