// B_20_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

struct Student {
	string First_name;
	string Last_name;
	string Group;
	int points[5];
	float averege;
	bool good_only;
};

int main() {
	int classes = 3;
	auto ch = new float[classes];
	ifstream input;
	input.open("input");
	ofstream output;
	output.open("output");
	Student people[10];
	for (int i = 0; i<classes; i++) {
		input » people[i].First_name;
		input » people[i].Last_name;
		input » people[i].Group;
		for (int j = 0; j<5; j++) {
			input » people[i].points[j];
			people[i].averege += people[i].points[j];
			if (people[i].points[j]>4 && people[i].points[j]<5) {
				people[i].good_only = true;
			}
			else people[i].good_only = false;
		}
		people[i].averege = people[i].averege / 5;

	}
	for (int i = 0; i<classes - 1; i++) {
		for (int j = 0; j<classes - 1 - i; j++) {
			if (people[j].averege>people[j + 1].averege) {
				Student tmp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i<classes; i++) {
		output « people[i].First_name«endl;
		output « people[i].Last_name«endl;
		output « people[i].Group«endl;
		output « people[i].averege«endl;
	}


	return 0;
}