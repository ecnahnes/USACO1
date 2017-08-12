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

int base4(const char (&input)[3])
{
	int number = 0;
	int base = 16;
	for (int i = 0; i < 3; ++i)
	{
		if (input[i] == 'A')
			number += 0;
		if (input[i] == 'C')
			number += base * 1;
		if (input[i] == 'G')
			number += base * 2;
		if (input[i] == 'T')
			number += base * 3;
		base /= 4;
	}
	return number;
}

bool isvalid(vector<string> &mappedval, int a, int b, int c, int N, int M)
{
	bool plain[64] = { false };
	bool valid = true;
	for (int i = 0; i < N; ++i)
	{
		char plaincow[3];
		plaincow[0] = (mappedval[i + N][a]);
		plaincow[1] = (mappedval[i + N][b]);
		plaincow[2] = (mappedval[i + N][c]);
		int coded = base4(plaincow);
		plain[coded] = true;
	}
	for(int j = 0; j < N; ++j)
	{
		char spotcow[3];
		spotcow[0] = (mappedval[j][a]);
		spotcow[1] = (mappedval[j][b]);
		spotcow[2] = (mappedval[j][c]);
		int coded2 = base4(spotcow);
		if (plain[coded2])
			valid = false;
	}
	return valid;
}

int main()
{
	ofstream fout("cownomics.out");
	ifstream fin("cownomics.in");
	int N, M;
	fin >> N >> M;
	std::vector<string> mappedval;
	for (int i = 0; i < 2 * N; ++i)
	{
		// A is 0
		// G is 1
		// C is 2
		// T is 3
		string cowgenome;
		fin >> cowgenome;
		mappedval.push_back(cowgenome);
	}
	int countvalid = 0;
	for (int a = 0; a < M; a++)
	{
		for (int b = a + 1; b < M; b++)
		{
			for (int c = b + 1; c < M; c++)
			{
				if (isvalid(mappedval, a, b, c, N, M) == true)
				{
					countvalid++;
				}
			}
		}
	}
	fout << countvalid;
	return 0;
}