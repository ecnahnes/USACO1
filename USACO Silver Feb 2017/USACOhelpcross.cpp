#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	ofstream fout("helpcross.out");
	ifstream fin("helpcross.in");
	int C, N;
	int total = 0;
	fin >> C >> N;
	vector<pii> cows;
	multiset<int> chicken;
	
	for (int i = 0; i < C; i++) 
	{ 
		int input1;
		fin >> input1; 
		chicken.insert(input1);
	}

	for (int i = 0; i < N; i++) 
	{ 
		int x, y;
		fin >> x >> y;
		cows.push_back(make_pair(y, x));
	}
	std::sort(cows.begin(), cows.end());

	for (int j = 0; j < N; j++) 
	{
		auto choose = chicken.lower_bound(cows[j].second);
		if (choose != chicken.end() && *choose <= cows[j].first) 
		{
			total++;
			chicken.erase(choose);
		}
	}

	fout << total << "\n";
	return 0;

}