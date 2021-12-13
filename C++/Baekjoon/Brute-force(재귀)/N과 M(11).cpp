#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int n, m;
int v[8];
int c[8];
unordered_map<string, int> um;

void BFS(int index, int cnt, string cur_str)
{
	// exit condition
	if (cnt == m)
	{
		if (um.find(cur_str) == um.end())
		{
			for (int i = 0; i < m; i++)
			{
				cout << c[i] << " ";
			}
			cout << '\n';
			um[cur_str] = 1;
		}
		return;
	}
	
	if (index >= n)
		return;

	for (int i = 0; i < n; i++)
	{
		c[cnt] = v[i];
		BFS(index, cnt + 1, cur_str + to_string(v[i]));
		//BFS(index + 1, cnt, cur_str);
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
		cin >> v[i];
	}
	sort(v, v + n);
	BFS(0,0,"");
	return 0;
}