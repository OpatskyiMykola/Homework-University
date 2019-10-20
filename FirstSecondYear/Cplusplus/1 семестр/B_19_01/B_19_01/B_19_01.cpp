#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "stdafx.h"
using namespace std;

int rot(int c, int k);


int rot1(int c, int litera, int k);

int main()
{
	ifstream File1; 
	File1.open("Govno_txt.txt");
	string  c;
	getline(File1, c);
	int k;
	cin >> k;
	for (int i = 0, n = c.length(); i<n; i++)
	{
		c[i] = rot(c[i], k);
		cout << c[i];
	}
	cout << endl;
}


int rot1(int c, int litera, int k)
{
	c = (c + k - litera) % 26 + litera;
	return c;
}

int rot(int c, int k)
{
	if (islower(c))
	{
		return rot1(c, 'a', k);
	}
	else if (isupper(c))
	{
		return rot1(c, 'A', k);
	}
	else return c;
}