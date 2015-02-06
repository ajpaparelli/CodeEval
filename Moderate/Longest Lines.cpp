// Longest Lines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void qs(vector<string> *V, int lo, int high)
{
	int i = lo, j = high;
	string tmp;
	int pivot = V->at((lo + high) / 2).size();

	while (i <= j)
	{
		while (V->at(i).size() < pivot)
			i++;
		while (V->at(j).size() > pivot)
			j--;
		if (i <= j)
		{
			tmp = V->at(i);
			V->at(i) = V->at(j);
			V->at(j) = tmp;
			i++;
			j--;
		}
	}

	if (lo < j)
		qs(V, lo, j);

	if (i < high)
		qs(V, i, high);	
}



int main(int argc, char *argv[])
{
	ifstream stream("C:\\test.txt");
	string line, templine;
	int n, x, y, z;
	vector<string> *vec = new vector<string>; 
	string s;
	x = 0;
	while (getline(stream, line)) {
		if (x == 0)
		{
			n = stoi(line);
			x = 1;
		}
		else
		{
			vec->push_back(line);
		}
	}

	if (vec->size() > 0)
	{
		qs(vec, 0, vec->size() - 1);
		for (x = 1; x <= n; x++)
		{
			cout << vec->at(vec->size() - x) << endl;
		}
	}
	return 0;
}

