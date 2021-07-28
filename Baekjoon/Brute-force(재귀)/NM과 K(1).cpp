#include <iostream>

using namespace std;

int M[10][10];
int check[10][10];
int n, m, k;
int res = -2100000000;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solution(int curX,int curY, int cnt, int total)
{
	if (cnt == k)
	{
		if (total > res)
			res = total;
		return;
	}

	for (int i = curX; i < n; i++)
	{
		for (int j = (i == curX ? curY : 0) ; j < m; j++)
		{
			if (check[i][j] == 1)
				continue;

			bool ok = true;
			for (int k = 0; k < 4; k++)
			{
				int nx = dx[k] + i;
				int ny = dy[k] + j;
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
				{
					if (check[nx][ny] == 1)
						ok = false;
				}
			}

			if (ok)
			{
				check[i][j] = 1;
				solution(i,j,cnt + 1,total + M[i][j]);
				check[i][j] = 0;
			}
		}
	}

}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
		}
	}
	solution(0,0,0,0);
	cout << res << '\n';
	return 0;
}