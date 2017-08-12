#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

unsigned long ID(int r1, int c1, int r2, int c2)
{
	unsigned long result = r1 * 1000000000 + c1 * 1000000 + r2 * 1000 + c2;
	return result;
}

unsigned long ID(int r, int c)
{
	unsigned long result = r * 1000 + c;
	return result;
}

void GetRowColFromID(const unsigned long id, int &row, int &col)
{
	row = (int)(id / 1000);
	col = (int)(id % 1000);
}

unsigned long bfs(const int N, const unsigned long cow, vector<vector<bool>> &fields, set<unsigned long> &walls, set<unsigned long> &cows)
{
	unsigned long total = 0;
	queue<unsigned long> q;
	q.push(cow);
	while (!q.empty())
	{
		int row, col;
		unsigned long id = q.front(); 
		q.pop();
		GetRowColFromID(id, row, col);
		bool visited = fields[row - 1][col - 1];
		if (visited) continue;
		if (cows.find(id) != cows.end()) ++total;
		fields[row - 1][col - 1] = true;
		if (col < N && fields[row-1][col] == false && (walls.find(ID(row, col, row, col+1)) == walls.end())) q.push(ID(row, col + 1));
		if (row > 1 && fields[row-2][col-1] == false && (walls.find(ID(row-1, col, row, col)) == walls.end())) q.push(ID(row - 1, col));
		if (col > 1 && fields[row-1][col-2] == false && (walls.find(ID(row, col, row, col-1)) == walls.end())) q.push(ID(row, col - 1));
		if (row < N && fields[row][col-1] == false && (walls.find(ID(row+1, col, row, col)) == walls.end())) q.push(ID(row + 1, col));
	}
	return total;
}

unsigned long countpairs(const int K, const int N, vector<vector<bool>> &fields, set<unsigned long> &walls, set<unsigned long> &cows)
{
	unsigned long pairs = (unsigned long)(K * (K -1)/2);
	for (auto cow : cows)
	{
		unsigned long temp = bfs(N, cow, fields, walls, cows);
		temp = (temp * (temp - 1)) / 2;
		pairs -= temp;
	}
	return pairs;
}

int main() 
{
	ofstream fout("countcross.out");
	ifstream fin("countcross.in");
	int N, K, R;
	fin >> N >> K >> R;
	std::set<unsigned long> walls;
	std::vector<vector<bool>> fields(N, vector<bool>(N));
	for (int i = 0; i < R; ++i)
	{
		int r1, c1, r2, c2;
		fin >> r1 >> c1 >> r2 >> c2;
		unsigned long id = ID(r1, c1, r2, c2);
		unsigned long id2 = ID(r2, c2, r1, c1);
		walls.insert(id);
		walls.insert(id2);
	}
	set<unsigned long> cows;
	for (int i = 0; i < K; ++i)
	{
		int r, c;
		fin >> r >> c;
		cows.insert(ID(r, c));
	}
	unsigned long count = countpairs(K, N, fields, walls, cows);
	fout << count;
	return 0;
}