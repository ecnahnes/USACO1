#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

long sqrdist(int x1, int y1, int x2, int y2)
{
	return((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int dfs(int current, vector<bool> &canHear, vector<vector<bool>> &canTransmit)
{
	if (canHear[current]) return 0;
	canHear[current] = true;
	int maximum = 1;
	int len = canTransmit[current].size();
	for (int i = 0; i < len; ++i)
	{
		if (canTransmit[current][i])
		{
			maximum += dfs(i, canHear, canTransmit);
		}
	}
	return maximum;
}

int main()
{
	ofstream fout("moocast.out");
	ifstream fin("moocast.in");
	int n;
	fin >> n;
	vector<int> x;
	vector<int> y;
	vector<int> p;
	for (int i = 0; i < n; ++i)
	{
		int xc, yc, pc;
		fin >> xc >> yc >> pc;
		x.push_back(xc);
		y.push_back(yc);
		p.push_back(pc);
	}
	
	vector<vector<bool>> canTransmit(n, vector<bool>(n));
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (sqrdist(x[i], y[i], x[j], y[j]) <= (long)p[i] * p[i])
			{
				canTransmit[i][j] = true;
			}
		}
	}

	int maximum = 1;
	for (int i = 0; i < n; ++i)
	{
		vector<bool> canHear(n);
		int pathMax = dfs(i, canHear, canTransmit);
		maximum = max(maximum, pathMax);
	}
	fout << maximum;
	return 0;
}