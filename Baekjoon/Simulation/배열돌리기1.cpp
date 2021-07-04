#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> func(vector<vector<int>> v)
{
	int n = v.size();
	int m = v[0].size();
	vector<vector<int>> temp(n,vector<int>(m,0));
	int r = 0, c = 0;
	//1 set
	while (n > r && m > c)
	{
		// 아래
		for (int i = r; i < n - 1; i++)
		{
			temp[i + 1][c] = v[i][c];
		}
		
		// 왼쪽
		for (int i = m - 1; i > c; i--)
		{
			temp[r][i - 1] = v[r][i];
		}

		// 오른쪽
		for (int i = c; i < m - 1; i++)
		{
			temp[n - 1][i + 1] = v[n - 1][i];
		}

		// 위쪽
		for (int i = n - 1; i > r; i--)
		{
			temp[i - 1][m - 1] = v[i][m - 1];
		}

		n = n - 1;
		m = m - 1;
		r += 1;
		c += 1;
	}

	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		v = func(v);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}