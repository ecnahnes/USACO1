#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct item
{
	int scount = 0, pcount = 0, hcount = 0;
	item()
	{

	}
	item(int s, int p, int h)
	{
		scount = s;
		pcount = p;
		hcount = h;
	}
	int maximum()
	{
		int max;
		max = (scount > pcount) ? scount : pcount;
		max = (max > hcount) ? max : hcount;
		return max;
	}
};

int main()
{
	ofstream fout("hps.out");
	ifstream fin("hps.in");
	int N;
	vector<string> gestures;
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		fin >> s;
		gestures.push_back(s);
	}
	int sc = 0, pc = 0, hc = 0;
	for (int i = 0; i < N; ++i)
	{
		if (gestures[i] == "S")	sc++;
		if (gestures[i] == "P")	pc++;
		if (gestures[i] == "H")	hc++;
	}
	if (sc > pc + hc)
		fout << sc;
	if (pc > sc + hc)
		fout << pc;
	if (hc > sc + pc)
		fout << hc;
	vector<item> forward(N);
	vector<item> backward(N);
	int s = 0, p = 0, h = 0;
	for (int i = 0; i < N; ++i)
	{
		if (gestures[i] == "S")	s++;
		if (gestures[i] == "P")	p++;
		if (gestures[i] == "H")	h++;
		forward[i] = item(s, p, h);
	}
	int scount = 0, pcount = 0, hcount = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		if (gestures[i] == "S")	scount++;
		if (gestures[i] == "P")	pcount++;
		if (gestures[i] == "H")	hcount++;
		backward[i] = item(scount, pcount, hcount);
	}
	int max = 0, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum = forward[i].maximum() + backward[i].maximum();
		max = (max > sum) ? max : sum;

	}
	fout << max;
	return 0;
}