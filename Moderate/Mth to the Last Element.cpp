// Mth to the Last Element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	string line;
	string tmp, n;
	vector <string> *v;
	int m, idx;
	while (getline(stream, line)) {
		if (line == "")
			continue;
		istringstream s2(line);
		v = new vector<string>();
		while (s2 >> tmp)
		{
			v->push_back(tmp);
		}
		n = v->at(v->size() - 1);
		m = stoi(n);
		v->pop_back();
		idx = v->size() - m;
		if (idx >= 0)
		{
			cout << v->at(idx) << endl;
		}
		delete(v);
	}
	// Do something with the line
	std::cin >> tmp;
	return 0;
}

