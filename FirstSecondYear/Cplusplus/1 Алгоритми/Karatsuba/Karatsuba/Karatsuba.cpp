#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

string sumIntStrToStr(string l, string r) {
	int a, b;
	string R1;
	/*for (int i = 0; i < l.size(); i++) {
		if (l[i] == '0') R1 += '0';
		else break;
	}*/

	a = atoi(l.c_str());
	b = atoi(r.c_str());

	return R1 + to_string(a + b);
}

string normalize_n(string n, string m) {
	int size_n = n.size();
	int size_m = m.size();
	int size = (size_n > size_m) ? size_n : size_m;      //довжина найдовшого числа
	//if (size % 2 == 1) size++;                         //робить довжину парною, якщо та не парна
	string rez = "";
	for (int i = 0; i < (size - n.size()); i++) rez += "0";           //додає нулі на початок
	return rez + n;
}
string normalize_m(string n, string m) {
	int size_n = n.size();
	int size_m = m.size();
	int size = (size_n > size_m) ? size_n : size_m;     //довжина найдовшого числа
	//if (size % 2 == 1) size++;                        //робить довжину парною, якщо та не парна
	string rez = "";
	for (int i = 0; i < (size - m.size()); i++) rez += "0";      //додає нулі на початок
	return rez + m;
}

string grinding_l(string nomb) {
	string rez = "";
	rez = nomb[0];
	for (int i = 1; i < nomb.size() / 2; i++) {
		rez += nomb[i];
	}
	return rez;
}
string grinding_r(string nomb) {
	string rez = "";
	rez += nomb[0];
	for (int i = nomb.size() / 2 + 1; i < nomb.size(); i++) {
		rez += nomb[i];
	}
	return rez;
}

long long Karatsuba(long long n, long long m) {
	int N = int(fmax(getLength(n), getLength(m)));
	cout << "n: " <<N<< endl;
	long long Rez;

	if (N < 2) {
		Rez = n * m;
	}
	else {
		N = (N / 2) + (N % 2);

		long long N_stepin = pow(10, N);

		long long n_r = n / N_stepin;
		cout << "n_r:  " << n_r << endl;
		long long n_l = n - (n_r * N_stepin);
		cout << "n_l:  " << n_l << endl;
		long long m_r = m / N_stepin;
		cout << "m_r:  " << m_r << endl;
		long long m_l = m - (m_r * N_stepin);
		cout << "m_l:  " << m_l << endl;

		long long c0 = Karatsuba(n_l, m_l);
		long long c1 = Karatsuba(n_l + n_r, m_l + m_r);
		long long c2 = Karatsuba(n_r, m_r);

		Rez = c0 + ((c1 - c0 - c2) * N_stepin) + (c2 * (long long)(pow(10, 2 * N)));
	}
	return Rez;

}

int main()
{
	long long  n, m;
	int exet;
	while (1) {
		cout << "Enter n and m: \n"; cin >> n >> m;

		cout << "Rez: " << Karatsuba(n, m) << endl;

		cout << "Again? (1 or 0): ";
		cin >> exet;
		if (exet == 0) break;
	}

	return 0;
}

