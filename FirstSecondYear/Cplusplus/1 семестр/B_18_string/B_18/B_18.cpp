#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	string S;
	cout << "Enter radok: \n";
	getline(cin, S);
	int wk1 = 0;
	int wk2;
	int kil = 0;
	for (int i = 0; i < S.size() ; i++) {
		if (S[i] == ' ' && S[i+1] != ' '){
			wk2 = i;
			int b = 0;
			for (int j = wk1; j < wk2; j++) {
				if (S[j] == 'b') {
					b++;
				}
				if (b == 3) {
					kil++;
			    }		
			}
			wk1 = wk2;
		}
	}
	int q;
	//cout << S;
	cout << "Sliw: " << kil;
	cin >> q;
	return 0;
}