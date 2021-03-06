#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

void DFS(int**G, int size_G, stack<int> stack, int Verch) {
	stack.push(Verch);
	cout <<  Verch + 1 << " ";
	G[Verch][Verch] = -1;
	for (int i = 0; i < size_G; i++) {
		if (i != Verch) {
			if (G[Verch][i] == 1) {
				G[Verch][i] = 0;
				G[i][Verch] = 0;
				if (G[i][i] != -1) {
					DFS(G, size_G, stack, i);
				}
			}
		}
	}
	//cout << "\nPop: " << Verch + 1 << endl;
	stack.pop();
}

int main() {
	int n;
	ifstream in("fin.txt");
	in >> n;
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			in >> matrix[i][j];
		}
	}
	cout << endl;
	stack<int> stack1;
	cout << "DFS: " << endl;
	cout << "Push: ";
	DFS(matrix, n, stack1, 0);
	
	cout << endl;
	system("pause");
	return 0;
}

