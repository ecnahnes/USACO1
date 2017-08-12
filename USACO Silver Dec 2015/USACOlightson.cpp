#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <fstream>

using namespace std;
static bool keepVisiting = true;

class Room
{
public:
		bool lighted;
		bool visited;
		int row;
		int column;
		vector<Room> lightableRooms;
		int RoomNumber()
		{
			return row * 100 + column;
		};
};

void visit(int r, int c, Room (&rooms)[100][100])
{
	rooms[r][c].visited = true;
	//Turn on lights
	vector<Room>::iterator it    = rooms[r][c].lightableRooms.begin();
	vector<Room>::iterator itEnd = rooms[r][c].lightableRooms.end();
	for (;it != itEnd; it++)
	{
		int row = it->row;
		int col = it->column;
		if(!rooms[row - 1][col - 1].lighted )
		{
			rooms[row - 1][col - 1].lighted = true;
			keepVisiting = true;

		}
	}

	if ((c - 1 >= 0) && (!rooms[r][c - 1].visited) && rooms[r][c - 1].lighted)
	{
		visit(r, c - 1, rooms);
	}
	if((r - 1 >= 0) && (!rooms[r - 1][c].visited) && rooms[r - 1][c].lighted)
	{
		visit(r - 1, c, rooms);
	}
	if((c + 1 >= 0) && (!rooms[r][c + 1].visited) && rooms[r][c + 1].lighted)
	{
		visit(r, c + 1, rooms);
	}
	if((r + 1 >= 0) && (!rooms[r + 1][c].visited) && rooms[r + 1][c].lighted)
	{
		visit(r + 1, c, rooms);
	}
}

int main()
{
	ofstream fout("lightson.out");
	ifstream fin("lightson.in");
	//read input
	int N, M;
	fin >> N >> M;
	Room rooms[100][100];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			rooms[i][j].row = i + 1;
			rooms[i][j].column = j + 1;
			rooms[i][j].lighted = false;
			rooms[i][j].visited = false;
		}
	}

	rooms[0][0].lighted = true;
	for (int i = 0; i < M; ++i)
	{
		int x, y, a, b;
		fin >> x >> y >> a >> b;
		rooms[x-1][y-1].lightableRooms.push_back(rooms[a-1][b-1]);
	}

	keepVisiting = true;
	map<int, Room> lightsOn;
	lightsOn[rooms[0][0].RoomNumber()] = rooms[0][0];

	while (keepVisiting)
	{
		keepVisiting = false;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				rooms[i][j].visited = false;
			}
		
	    visit(0,0, rooms);

     }

	int count = 0;
 	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (rooms[i][j].lighted)
			{
				//cout << rooms[i][j].row << " " << rooms[i][j].column << endl;
				count++;
			}
		}
	fout << count;
	return 0;
}