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

struct PCL 
{ 
	int i1, j1, i2, j2; 
};

int main()
{
	ifstream fin("where.in");
	ofstream fout("where.out");
	int N;
	vector<PCL> V;
	fin >> N;
	for (int i = 0; i < N; i++)

	int answer = 0;
	for (int i = 0; i < V.size(); i++)
	fout << answer << "\n";
	return 0;