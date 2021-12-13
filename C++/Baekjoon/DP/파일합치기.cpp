#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int File[501];
int d[501][501];

int solution(int i, int j)
{
	if (i == j)
		return 0;

	if (d[i][j] != -1)
		return d[i][j];

	int& ans = d[i][j];
	int sum = 0;
	for (int t = i; t <= j; t++)
		sum += File[t];

	for (int k = i; k <= j - 1; k++)
	{
		int temp = solution(i, k) + solution(k + 1, j) + sum;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}

int main()
{
	int T, k; // T : TestCase || k : °¢ testcase File °¹¼ö	
	cin >> T; 
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		memset(d,-1,sizeof(d));
		for (int j = 0; j < k; j++)
		{
			cin >> File[j];
		}
		cout << solution(0, k - 1) << endl;
	}	
	
	return 0;
}
