// FibonacciSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int fibonacci(int);

int main(int argc, char* argv[])
{
	ifstream file;
	string lineBuffer;

	file.open(argv[1]);

	while (!file.eof())
	{
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else
		{
			istringstream buffer(lineBuffer);
			int n;
			buffer >> n;
			cout << fibonacci(n) << endl;
		}
	}
}


int fibonacci(int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

