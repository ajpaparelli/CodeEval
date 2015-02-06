// LCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int lcs(string X, string Y, int m, int n)
{
	
	int **L;
	L = new int*[m+1];
	for (int i = 0; i <= m; i++)
		L[i] = new int[n+1];
	int maxstr = 0;
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1];
			else			
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);		

		}
	}	
	maxstr = L[i][j];
	delete L;
	return maxstr;
}

int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line;

    int delim;
	string s1, s2;
	string tmp, n;
	delim = 0;
	while (getline(stream, line)) {
		if (line == "")
			continue;
		delim = line.find(';');
		if (delim > 0)
		{
			tmp = line.substr(0, delim);
			s1 = tmp;
			tmp = line.substr(delim + 1, (line.length()-delim-1));
			s2 = tmp;
			lcs(s1, s2, s1.length(), s2.length());
		}
	}
	cin >> tmp;

	return 0;
}
