// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line, templine;
	while (getline(stream, line)) {
		vector<string> vec;
		istringstream iss(line);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(vec));

		for (int x = 0; x < vec.size(); x++)
			templine = vec[x] + " " + templine;

		cout << templine << endl;
		templine = "";
	}
	return 0;
}

