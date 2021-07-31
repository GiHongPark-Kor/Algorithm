#include <iostream>
#include <queue>
using namespace std;

int current_max;
int n, m;
int M[9][9];
int M2[9][9];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1};

void count_safe_area()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (M2[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					if (0 <= nx && nx < n && 0 <= ny && ny < m)
					{
						if (M2[nx][ny] == 2)
						{
							M2[i][j] = 2;
							count_safe_area();
							break;
						}
					}
				}
			}
		}
	}
}

void func(int one_cnt)
{
	// exit condition
	if (one_cnt == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				M2[i][j] = M[i][j];
			}
		}
		count_safe_area();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (M2[i][j] == 0)
					cnt += 1;
			}
		}

		if (current_max < cnt)
		{
			current_max = cnt;
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (M[i][j] == 0)
			{
				M[i][j] = 1;
				func(one_cnt + 1);
				M[i][j] = 0;
			}
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
		}
	}
	func(0);
	cout << current_max << endl;
	return 0;
}