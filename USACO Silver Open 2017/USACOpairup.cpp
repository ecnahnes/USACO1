#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
	ofstream fout("pairup.out");
	ifstream fin("pairup.in");
	vector<pair<int, int>> timepairs;
	int N;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		fin >> x >> y;
		timepairs.push_back(make_pair(y, x));
	}
	sort(timepairs.begin(), timepairs.end());
	int start = 0;
	int finish = N - 1;
	int ret = 0;
	while (start <= finish)
	{
		int mincount = min(timepairs[start].second, timepairs[finish].second);
		ret = max(ret, timepairs[start].first + timepairs[finish].first);
		if (start == finish)
		{
			break;
		}
		timepairs[start].second = timepairs[start].second - mincount;
		timepairs[finish].second = timepairs[finish].second - mincount;
		if (timepairs[finish].second == 0)
		{
			finish--;
		}
		if (timepairs[start].second == 0)
		{
			start++;
		}
	}
	fout << ret << "\n";
	return 0;
}