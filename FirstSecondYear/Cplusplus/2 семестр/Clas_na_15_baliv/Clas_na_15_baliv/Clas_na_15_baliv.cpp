#include "stdafx.h"
#include "Kolo.h"

int main(){
	int n = 3;

	Kolo *obgect = new Kolo[n];
	for (int i = 0; i < n; i++) {
		cout << "Kolo N" << i+1 << endl;
		obgect[i] >> cin;
		obgect[i].setname(i+1);
	}
	for (int i = 0; i < n; i++) {
		cout << "\nKolo N" << i+1 <<": "<<endl;
		obgect[i] << cout;
	}
	cout << endl;
	cout << "\nmax S_osnovu: \n";
	for (int i = 0; i < n-1; i++) {
		if ( obgect[i].S_osn() > obgect[i+1].S_osn()) {
			Kolo tmp = obgect[i];
			obgect[i] = obgect[i + 1];
			obgect[i + 1] = tmp;
		}
	}
	 cout << obgect[n-1].S_osn();
	 cout << "\nIt`s a kolo N"; obgect[n - 1].outputname();
	 cout << endl<< "peretunu: "<<endl;
	 cout << "1 z 2: ";  obgect[0].peretn(obgect[1]);
	 cout << "\n1 z 3: "; obgect[0].peretn(obgect[2]);
	 cout << "\n2 z 3: "; obgect[1].peretn(obgect[2]);

	delete [] obgect;
	cout << endl;
	system("pause");
    return 0;
}

