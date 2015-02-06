// MultiplesOfANumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/*
*
*/

int findmax(int i1, int i2)
{
	int x = 1;	
	while ((i2*x) < i1)
		x++;
	return i2*x;
}
int main(int argc, char* argv[]) {
	ifstream file(argv[1]);
	string line, tmp;
	int i1, i2;
	int delim;
	while (getline(file, line)) {
		if (line == "")
			continue;
		delim = line.find(',');
		if (delim > 0)
		{
			tmp = line.substr(0, delim);
			i1 = stoi(tmp);
			tmp = line.substr(delim + 1, (line.length() - delim - 1));
			i2 = stoi(tmp);
		}
		cout << findmax(i1, i2) << endl;

	}

	return 0;
}

