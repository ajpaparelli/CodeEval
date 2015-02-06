// Detecting Cycles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void split(const string &txt, vector<string> *vec, char ch)
{
	unsigned int pos = txt.find(ch);
	unsigned int init_pos = 0;

	vec->clear();
	while (pos != string::npos)
	{
		vec->push_back(txt.substr(init_pos, pos - init_pos + 1));
		init_pos = pos + 1;
		pos = txt.find(ch, init_pos);
	}

	vec->push_back(txt.substr(init_pos, min(pos, txt.size()) - init_pos + 1));
}

string findcycle(vector<string> *v)
{
	int t, h = 0;
	int max_step = 2;
	int steps = 0;
	string ret = "";

	if ((v->size() == 0) || (v->size() == 1))
		return NULL;
	//move the hare to the first element = 2 steps from head
	h = 1;	
	steps++; steps++;
	while (h < v->size())
	{
		if (v->at(t) == v->at(h))
		{
			return v->at(t);
		}

		if (steps == max_step)
		{
			steps = 0;
			max_step *= 2;
			t = h;
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line;

	vector<string> *v = new vector<string>();
	string tmp, n;
	string s1;	
	int a, b;
	while (getline(stream, line)) {
		if (line == "")
			continue;
		split(line, v, ' ');
		
		
	}	
	cin >> tmp;
	delete(v);

	return 0;
}

