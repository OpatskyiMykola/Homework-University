#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long A, B, R = 0, count = 0, n;

	cout << "Enter \nA: ";	cin >> A;
	cout << "B: "; cin >> B;

	while (A >= 1) {
		if (A % 2 == 1) {
			R += B;
			//count++;
		}

		A /= 2;
		B *= 2;
		count += 2;
	}

	cout << "Rez: " << R << endl;
	cout << "count: " << count << endl;
	system("pause");
	return 0;
}

