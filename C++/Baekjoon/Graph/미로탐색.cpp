// start : 14 : 25
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int M[100][100];
int check[100][100];
int dx[] = { 0, 0, -1, 1};
int dy[] = { 1, -1, 0, 0};
int n, m;

typedef struct pos
{
	int x;
	int y;
	int v;
}pos;
int res;
void BFS(int x, int y)
{
	queue <pos> q;
	check[x][y] = 1;
	q.push({x,y,1});
	while (!q.empty())
	{
		pos p = q.front();
		q.pop();
		if (p.x == n - 1 && p.y == m - 1)
		{
			res = p.v;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + p.x;
			int ny = dy[i] + p.y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (check[nx][ny] == 0 && M[nx][ny] == 1)
				{
					check[nx][ny] = 1;
					q.push({nx,ny,p.v + 1});
				}
			}
		}
	}

		
	
}

int main()
{
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			M[i][j] = str.at(j) - '0';
		}
	}
	BFS(0,0);
	cout << res << '\n';
	return 0;
}
