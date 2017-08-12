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
	ofstream fout("maxcross.out");
	ifstream fin("maxcross.in");
	int N, K, B;
	vector<bool> lights;
	fin >> N >> K >> B;
	for (int i = 0; i < N; ++i)
	{
		lights.push_back(true);
	}
	for (int i = 0; i < B; i++)
	{
		int index;
		fin >> index;
		lights[index-1] = false;
	}
	int minimum = 0;
	for (int i = 0; i < K; i++)
	{
		if (lights[i] == false)
			minimum++;
	}
	int bad = minimum;
	for (int i = 0; i <= N - K - 1; ++i)
	{
		if (lights[i] != lights[i + K])
		{
			if (lights[i + K] == false)
				bad++;
			if (lights[i + K] == true)
			{
				bad--;
				if (bad < minimum)
					minimum = bad;
			}
		}

	}
	fout << minimum;
	return 0;
}