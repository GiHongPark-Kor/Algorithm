#include <iostream>
#include <algorithm>
using namespace std;

int a[5001];
int b[5001];
int d[5001][5001];

int main()
{
	int n, input;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// input
	cin >> n;
	for (int i = 1; i <= n; i++)
	{		
		cin >> input;
		a[i] = input;
		b[n + 1 - i] = input;
		
	}

	// LCS(Longest Common Subsequence) 길이 구하기
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[j] == b[i]) // 같을 때
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else // 다를 때
			{
				d[i][j] = max(d[i-1][j], d[i][j - 1]);
			}
		}
	}

	cout << n - d[n][n] << '\n';

	return 0;
}