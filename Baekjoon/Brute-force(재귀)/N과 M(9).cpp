#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
int v[9];
int c[9];
int res[9];
int n, m;
int umCount;
unordered_map<string, int> um;

void BFS(int cnt, string str)
{
	//exit condition
	if (cnt == m )
	{
		if (um.find(str) == um.end())
		{
			um[str] = 1;
			for (int i = 0; i < m; i++)
			{
				cout << res[i] << " ";
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
		{
			c[i] = 1;
			res[cnt] = v[i];
			BFS(cnt + 1, str + to_string(v[i]));
			c[i] = 0;
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
		cin >> v[i];
	sort(v, v + n);
	BFS(0,"");

	return 0;
}