#include <iostream>
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
	ofstream fout("angry.out");
	ifstream fin("angry.in");
	vector<int> location;
	int N, K;
	fin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int loc;
		fin >> loc;
		location.push_back(loc);
	}
	sort(location.begin(), location.end()); 
	int start = 0;
	int end = 500000000;
	while(start != end)
	{
		int mid = (start + end) / 2;
		int last = 0;
		int used = 0;
		while(last < N)
			used++;
			int curr = last + 1;
			while (curr < N && (location[curr] - location[last] <= 2 * mid)) 
			{
				curr++;
			}
		last = curr;
		if ()
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	fout << start;
	return 0;
}