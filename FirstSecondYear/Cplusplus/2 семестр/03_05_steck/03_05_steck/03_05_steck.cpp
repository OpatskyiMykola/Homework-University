#include "stdafx.h"
#include <iostream>
#include "PidPrograma.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter n: "; cin >> n;

	PidPrograma Arr(n);
	
	Arr.Out();

	cout << endl;
	system("pause");
    return 0;
}


//pop - забрати
//push - запхати

