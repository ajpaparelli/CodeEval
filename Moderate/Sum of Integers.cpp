// Sum of Integers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void split(const string& s, char c, vector<int>& v)
{
	string::size_type i = 0;
	string::size_type j = s.find(c);
	string tmpstr;
	while (j != string::npos) {
		tmpstr = s.substr(i, j);
		v.push_back(stoi(tmpstr));
		i = ++j;
		j = s.find(c, j);
		if (j == string::npos)
			v.push_back((stoi(s.substr(i, s.length()))));
	}
}

int findMax(vector<int> v)
{
	int max_sf = v[0];
	int max_eh = v[0];

	for (int x = 1; x < v.size(); x++)
	{
		max_eh = max(v[x], max_eh + v[x]);
		max_sf = max(max_sf, max_eh);
	}
	return max_sf;
}

int main(int argc, char* argv[])
{

	ifstream stream(argv[1]);
	string line, templine;
	vector<int> v;

	while (getline(stream, line)) {
		if (line.length() > 0)
		{
			split(line, ',', v);
			cout << findMax(v) << endl;
			v.clear();
		}
	}
	stream.close();
	cin >> templine;
	return 0;
}

