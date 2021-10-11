#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L[31][11];
int n, m, h;
int a, b;
int min_value = 2100000000;
bool dfs_check; // 사다리 결과 check

/* (j번 째 사다리 결과 == j) check */
bool test(int i, int j, int target)
{
	if (i == h + 1)
	{
		if (j == target)
			return true;
		else
			return false;
	}

	if (L[i][j] == 0)
	{
		return test(i + 1, j, target);
	}
	else
	{
		if (L[i][j] == 1)
		{
			return test(i + 1, j + 1, target);
		}
		else if (L[i][j] == -1)
		{
			return test(i + 1, j - 1, target);
		}
	}
}

void dfs(int i , int j, int cnt)
{
	if (cnt > 3)
	{
		return;
	}

	if (j >= n && i >= h) // exit condition
	{

		for (int k = 1; k <= n; k++)
		{
			dfs_check = test(1, k, k);
			if (dfs_check == false)
				break;
		}
		if (cnt < min_value && dfs_check == true)
		{
			min_value = cnt;
		}
		return;
	}

	if (j == n)
		dfs(i + 1, 1, cnt);
	else
	{
		// visit
		if (L[i][j] == 0  && L[i][j - 1] != 1 && L[i][j + 1] != 1)
		{
			L[i][j] = 1;
			L[i][j + 1] = -1;
			dfs(i, j + 1, cnt + 1);
			L[i][j] = 0;
			L[i][j + 1] = 0;

		}

		// not visit
		dfs(i, j + 1, cnt);
	}
}

int main()
{
	bool check = false;
	cin >> n >> m >> h;

	/* input */
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		L[a][b] = 1;
		L[a][b + 1] = -1;
	}

	/* dfs 시작 전 사다리게임 check */
	for (int i = 1; i <= n; i++)
	{
		check = test(1, i, i);
		if (check == false)
			break;
	}

	if (check == true) 
	{
		/* 선 추가 없이 가능*/
		cout << 0 << endl;
	}
	else
	{
		dfs(1,1,0);
		if (min_value > 3)
			cout << -1 << endl;
		else
			cout << min_value << endl;

	}
	return 0;
}