//start : 03 : 15
//end : 03 : 33
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int M[26][26];
int check[26][26];
int N;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
int cnt = 1;
void DFS(int r, int c)
{
	check[r][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		int cx = r + dx[i];
		int cy = c + dy[i];
		if (cx >= 0 && cx < N && cy >= 0 && cy < N)
		{
			if (check[cx][cy] == 0 && M[cx][cy] == 1)
			{
				DFS(cx,cy);
				cnt++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			M[i][j] = str.at(j) - '0';
		}
	}
	int num = 0;
	vector<int> house_cnt;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (M[i][j] == 1 && check[i][j] == 0)
			{
				DFS(i,j);
				num += 1;
				house_cnt.push_back(cnt);
				cnt = 1;
			}
		}
	}
	sort(house_cnt.begin(), house_cnt.end());
	cout << num << '\n';
	for (int i = 0; i < house_cnt.size(); i++)
		cout << house_cnt[i] << '\n';

	return 0;
}