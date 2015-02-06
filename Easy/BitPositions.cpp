// BitPositions.cpp : Defines the entry point for the console application.
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

int main(int argc, char* argv[]) {
	ifstream file(argv[1]);
	string line;
	int i1, i2, i3;	
	int delim;
	int next;
	while (getline(file, line)) {
		if (line == "")
			continue;
		delim = line.find(',');
		if (delim > 0)
		{
			i1 = atoi(line.substr(0, delim).c_str());
			next = delim + 1;
			delim = line.find(',', delim + 1);
			i2 = atoi(line.substr(next, (line.length() - delim - 1)).c_str())-1;
			next = delim + 1;
			delim = line.find(',', delim + 1);
			i3 = atoi(line.substr(next, (line.length() - delim - 1)).c_str())-1;
		}

		if (((i1 >> i2) & 1) == ((i1 >> i3) & 1))
			cout << "true" << endl;
		else
			cout << "false" << endl;

	}

	return 0;
}

