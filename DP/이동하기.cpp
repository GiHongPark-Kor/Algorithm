#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>MAP(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>DP(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> MAP[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			DP[i][j] = max(DP[i-1][j],DP[i][j-1]) + MAP[i][j];
		}
	}
	cout << DP[n][m] << endl;
	return 0;
}