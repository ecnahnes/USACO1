#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

char parse(string s, long index) 
{
	long length = s.size();
	if (index < length) 
	{
		return s[(int)index];
	}
	while (2 * length <= index)
	{
		length *= 2;
	}
	if (index == length)
	{
		return parse(s, index - 1);
	}
	return parse(s, index - length - 1);
}
int main()
{
	ofstream fout("cowcode.out");
	ifstream fin("cowcode.in");
	long N;
	string s;
	fin >> s >> N;
	char c = parse(s, N-1);
	out << c;
	return 0;
}