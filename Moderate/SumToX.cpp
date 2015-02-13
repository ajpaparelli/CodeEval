// SumToX.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
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

int main(int argc, char *argv[])
{	
	ifstream stream(argv[1]);
	string line;
	string tmp;
	char delim;
	string s1, s2;
	vector<int> in_list;
	while (getline(stream, line)) {
		if (line == "")
			continue;
		delim = line.find(';');
		if (delim > 0)
		{
			tmp = line.substr(0, delim);
			s1 = tmp;
			split(s1, ',', in_list);

			tmp = line.substr(delim + 1, (line.length() - delim - 1));
			s2 = tmp;
		}

		int sum = stoi(s2);

		int _hash[10000] = { 0 };
		int count = 0;
		string A[10000] = { "" };

		for (int i = 0; i < in_list.size(); i++)
		{

			int k = sum - in_list[i];
			if (k >= 0 && _hash[k] == 1)
			{
				A[count] = to_string(k) + "," + to_string(in_list[i]);
				count++;
			}
			_hash[in_list[i]] = 1;
			
		}
		if (count == 0)
			cout << "NULL";
		else {
			for (int i = count - 1; i >= 0; i--) {

				cout << A[i];
				if (i > 0)
					cout << ":";
			}
		}
		cout << endl;
	}
	return 0;
}

