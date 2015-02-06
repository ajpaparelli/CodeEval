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
		int sum = 0;
		for (int x = 0; x < line.size(); x++)
		{
			char* c = new char(line[x]);
			sum = sum + atoi(c);
			delete(c);
		}
		
		cout << sum << endl;
	}
	return 0;
}
