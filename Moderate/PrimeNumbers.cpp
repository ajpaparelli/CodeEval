// PrimeNumbers.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int i)
{
	bool result = true;
	if ((i == 2) || (i == 3))
	{
		result = true;
	}
	else
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	ifstream stream("C:\\test.txt");
	string line, templine;
	int x, y,z ;
	vector<int> vec;
	string s;
	while (getline(stream, line)) {
		x = stoi(line);
		s = "";
		if (vec.size() == 0)
		{
			for (y = 2; y <= x; y++)
			{
				if (isPrime(y))
				{
					s = s + to_string(y) + ",";
					vec.push_back(y);
				}
			}
		}
		else
		{
			if (vec.back() > x)
			{
				y = 0;
				while (vec[y] <= x)
				{
					int tmp = vec[y];
					s = s + to_string(tmp) + ",";
					y++;
				}
			}
			else
			{
				z = vec.size();
				for (y = 0; y < vec.size(); y++)
				{
					int tmp = vec[y];
					s = s + to_string(tmp) + ",";
				}
				
				for (y = vec.back()+1; y <= x; y++)
				{
					if (isPrime(y))
					{
						s = s + to_string(y) + ",";
						vec.push_back(y);
					}
				}
			}
		}
		s.erase(s.end()-1);
		cout << s << endl;


	}
	return 0;
}

