#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("haybales.out");
	ifstream fin("haybales.in");
	vector<int> hay;
	vector<int> loc;
	int n, q;
	fin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		int s;
		fin >> s;
		hay.push_back(s);
	}
	for (int j = 0; j < 2 * q; ++j)
	{
		int a;
		fin >> a;
		loc.push_back(a);
	}
	std::sort(hay.begin(), hay.end());
	for (int x = 0; x < 2 * q; x = x + 2)
	{
		int lower = loc[x];
		auto lindex = std::lower_bound(hay.begin(), hay.end(), lower);
		int upper = loc[x + 1];
		auto uindex = std::upper_bound(hay.begin(), hay.end(), upper);
		int count = std::distance(lindex, uindex);
		fout << count << endl;
	}
	return 0;
}