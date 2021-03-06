#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person{
public:
	string first_name;
	string second_name;

	Person(): first_name("A1"), second_name("B1") {};
	Person(string first_name,	string second_name) {};
	virtual void ShowInfo() = 0;

};

class Student:public Person{
public:
	double SerBal;
	Student() {};
	Student(string _first_name, string _second_name, double _SerBal) {
		first_name = _first_name; second_name = _second_name;  SerBal = _SerBal;
	};
	void ShowInfo() {
		cout << first_name << " " << second_name << endl;
		cout << "SerBal: " << SerBal << endl;
	}

};


class Lecturer : public Person {
public:
	int count_publacation;
	string Posada;
	int old;
	Lecturer() {};
	Lecturer(string _first_name, string _second_name, int _count_publacation, string _Posada, int _old) { 
		first_name = _first_name; second_name = _second_name; count_publacation = _count_publacation; Posada = _Posada; old = _old;
	};
	void ShowInfo() {
		cout << first_name << " " << second_name << endl;
		cout << "Publication: " << count_publacation << endl;
		cout << "posada: " << Posada << endl;
		cout << "Older: " << old << endl;
	}

};



int main(){
	ifstream in("Text.txt");
	int n;
	do{
	cout << "Enter n: "; cin >> n;
	}while (n > 3);
	//in >> n;
	
	string f_name;
	string s_name;
	int statti;
	string pos;
	double old;
	double bal;

	Person **Obj = new Person *[n];
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			in >> f_name >> s_name >> statti >> pos >> old;
			
			Obj[i] = new Lecturer(f_name, s_name, statti, pos, old);
			Obj[i]->ShowInfo();
		}
		else {
			in >> f_name;
			in >> s_name;
			in >> bal;
			Obj[i] = new Student(f_name, s_name, bal);
			Obj[i]->ShowInfo();
		}
	}
	system("pause");
    return 0;
}

