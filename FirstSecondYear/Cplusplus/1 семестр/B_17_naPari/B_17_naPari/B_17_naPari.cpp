#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char ryadok[20];
	cout << "Enter radok: \n";
	gets_s(ryadok);
	int count_a = 0;
	//char bukla[] = { 'a' };

	for (int i = 0; i < 20; i++) {
		if (ryadok[i] == 'a') {
			count_a++;
		}
	}
	int q;
	cout << "Sliw: " << count_a;
	cin >> q;
	return 0;
}