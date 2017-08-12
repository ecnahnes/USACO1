#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <climits>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool ispossible(vector<int> times, int K, int maxTime)
{
	int timeElapsed = 0;
	priority_queue<int, std::vector<int>, std::greater<int>> q;
	int len = times.size();
	for (int i = 0; i < len; ++i) 
	{
		if (q.size() == K) 
		{
			timeElapsed = q.top();
			q.pop();
		}
		if (timeElapsed + times[i] > maxTime) 
		{
			return false;
		}
		q.push(timeElapsed + times[i]);
	}
	return true;
}

int main()
{
	ofstream fout("cowdance.out");
	ifstream fin("cowdance.in");
	int N, T;
	vector<int> times;
	fin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		int b;
		fin >> b;
		times.push_back(b);
	}
	int min = 1, max = N;
	while (min < max)
	{
		int mid = (min + max) / 2;
		if(ispossible(times, mid, T) == true)
		{
			max = mid;
		}
		else
		{
			min = mid + 1;
		}
	}
	fout << min;
	return 0;
}