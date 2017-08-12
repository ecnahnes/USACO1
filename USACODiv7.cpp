#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
	ofstream fout("div7.out");
	ifstream fin("div7.in");
	int n;
	fin >> n;
	vector<int> id(n+1,0);
	int temp;
	for (int i = 1; i <= n; ++i)
	{
		fin >> temp;
		id[i] = (id[i-1] + temp) % 7;
	}
	vector<int> dis(7, -1);
	int ret = 0;
	for (int j = 1; j <= n; ++j)
	{
		if (dis[id[j]] == -1)
		{
			dis[id[j]] = j;
		}
		else
		{
			ret = max(ret, j - dis[id[j]]);
		}
	}
	fout << ret;
	return 0;
}