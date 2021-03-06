#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

int* el_dvoh(int n, int* arr1, int* arr2) {
	int* arr_2_arr = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i] == arr2[j])
				arr_2_arr[i] = arr2[j];
			else arr_2_arr[i] = -100;
		}
	}
	return arr_2_arr;
}

int* el_perhogo(int n, int* arr1, int* arr2) {
	int* arr_1_arr = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i] != arr2[j])
				arr_1_arr[i] = arr1[i];
			else arr_1_arr[i] = -100;
		}
	}
	return arr_1_arr;
}

void main_Funk(int n, int* arr1, int* arr2,  int* el_perhogo(int n, int* arr1, int* arr2),  int* el_dvoh(int n, int* arr1, int* arr2)) {
	cout << "\nEl dvoh: \n";
	int* arr_2_arr = el_dvoh(n, arr1, arr2);
	for (int i = 0; i < n; i++) {
		if(arr_2_arr[i] != -100)
		cout << arr_2_arr[i] << " ";
	}
	cout << "\nEl perhogo: \n";
	int* arr_1_arr = el_perhogo(n, arr1, arr2);
	for (int i = 0; i < n; i++) {
		if (arr_1_arr[i] != -100)
		cout << arr_1_arr[i] << " ";
	}
}

int main(){
	int n;
	cout << "n: ";
	cin >> n;

	int* arr1 = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++) {
		arr1[i] = -50 + rand()%51;
		arr2[i] = -50 + rand()%51;
	}
	cout << "mass: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	main_Funk(n, arr1, arr2, el_perhogo, el_dvoh);
	

	cout << endl;
	system("pause");
    return 0;
}

