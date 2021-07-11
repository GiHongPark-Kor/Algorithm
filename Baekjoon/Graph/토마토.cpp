// start : 04 : 48
// end : 05 : 07

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int m, n;
int M[1001][1001];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0 ,0 };
typedef struct pos
{
	int x;
	int y;
	int t;
}pos;

int main()
{
	int res = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	queue<pos> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 1)
			{
				q.push({i,j,0});
			}
		}
	}

	while (!q.empty())
	{
		pos p = q.front();
		int curX = p.x;
		int curY = p.y;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (M[nx][ny] == 0)
				{
					M[nx][ny] = 1;
					q.push({nx,ny,p.t + 1});
					if (res < p.t + 1)
					{
						res = p.t + 1;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (M[i][j] == 0)
			{
				cout << "-1" << '\n';
				return 0;
			}
		}
	}

	cout << res << '\n';
	return 0;
}