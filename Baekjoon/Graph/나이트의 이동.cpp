// start : 05 : 25
// end : 05 : 42

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int check[301][301];

int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = { 2, 2, 1, -1, -2, -2, -1, 1 };

typedef struct Pos
{
	int x;
	int y;
	int c;
}Pos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	int S;
	pair <int, int> cur;
	pair <int, int> next;


	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> S;
		cin >> cur.first >> cur.second;
		cin >> next.first >> next.second;
		int M[301][301];
		int check[301][301];
		memset(check, 0, sizeof(check));
		queue<Pos>q;
		q.push({cur.first,cur.second,0});
		while (!q.empty())
		{
			Pos p = q.front();
			q.pop();
			if (p.x == next.first && p.y == next.second)
			{
				cout << p.c << '\n';
				break;
			}
			for (int j = 0; j < 8; j++)
			{
				int nx = p.x + dx[j];
				int ny = p.y + dy[j];
				if (nx >= 0 && nx < S && ny >= 0 && ny < S)
				{
					if (check[nx][ny] == 0)
					{
						check[nx][ny] = 1;
						q.push({ nx,ny,p.c + 1 });
					}
				}

			}
		}

	}

	return 0;
}
