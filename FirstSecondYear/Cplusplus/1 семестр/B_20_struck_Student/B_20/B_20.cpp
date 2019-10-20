#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include  <algorithm>
#include <utility>
using namespace std;
struct Student {
	string name;
	string inicial;
   string  Grup;
   int Ngrup;
	int bal[5];
	float SerBal = 0;
};

int main(){
	Student G[10];
	ifstream input;
	input.open("Gov.txt");
	for (int i = 0; i < 10; i++) {
		input >> G[i].name;
		input >> G[i].inicial;
		input >> G[i].Grup;
		input >> G[i].Ngrup;
		for (int j = 0; j < 5; j++) {
			input >> G[i].bal[j];
		}
	}
	//Сер Бал
	for (int i = 0; i < 10; i++) {
		G[i].SerBal = 0;
		for (int j = 0; j < 5; j++) {
			G[i].SerBal += G[i].bal[j];
		}
		G[i].SerBal = G[i].SerBal / 5;
	}
              	//Говносорт
	for (int i = 0; i < 9; i++) {                 
		for (int j = 0; j < 9; j++) {
			if (G[j].Ngrup > G[j + 1].Ngrup) {       // Сорт по групі
				swap(G[j], G[j + 1]);
			}
			if (G[j].Ngrup == G[j + 1].Ngrup) {      // Сорт по імені
				if (G[j].name > G[j + 1].name) {
					swap(G[j], G[j + 1]);
				}
			}
		}
	}
	cout << "Step 1: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << G[i].Grup << " " << G[i].Ngrup << endl;
		cout << G[i].name << " " << G[i].inicial << endl;
		cout << G[i].SerBal << endl;
	}
	cout << "Step 2:" << endl;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (G[i].SerBal >= 4.0) {
			cout << G[i].Grup << " " << G[i].Ngrup << endl;
			cout << G[i].name << " " << G[i].inicial << endl;
		}
		else count++;
	}
	if (count == 10) cout << "messeg." << endl;

	system("pause");
    return 0;
}