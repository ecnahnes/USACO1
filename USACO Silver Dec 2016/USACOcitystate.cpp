#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

string revert(string input)
{
	return input.substr(2, 2) + input.substr(0, 2);
}

int main()
{
	ofstream fout("citystate.out");
	ifstream fin("citystate.in");
	map<string, int> places;
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		string city, state;
		fin >> city >> state;
		string two = city.substr(0, 2);
		if (two != state)
		{
			string place = city.substr(0, 2) + state;
			if (places.find(place) == places.end())
			{
				places[place] = 1;
			}
			else
			{
				++places[place];
			}
		}
	}
	long total = 0;
	for (auto p : places)
	{
		string rev = revert(p.first);
		if (places.find(rev) != places.end())
		{
			total += (places[p.first] * places[rev]);
		}
	}
	fout << total/2;
	return 0;
}