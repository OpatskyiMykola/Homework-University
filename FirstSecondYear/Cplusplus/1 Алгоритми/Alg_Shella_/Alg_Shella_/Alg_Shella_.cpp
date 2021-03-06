#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int* sort_shell(int *a, int N, int DDD) {
	for (int d = DDD / 2; d >= 1; d /= 2)
		for (int i = d; i < N; i++)
			for (int j = i; j >= d && a[j - d] > a[j]; j -= d)
				swap(a[j], a[j - d]);

	return a;
}

int main(){
	int n;
	int d;
	cout << "Enter size: "; cin >> n;
	cout << "Enter d: "; cin >> d;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;
	A = sort_shell(A, n, d);
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;


	system("pause");
    return 0;
}

