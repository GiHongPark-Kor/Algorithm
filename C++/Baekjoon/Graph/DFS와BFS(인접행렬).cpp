// start : 03 : 13
// end : 03 : 29

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int n, m;
int M[1001][1001];
int check[1001];

void DFS(int v)
{
	check[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= 1000; i++)
	{
		if (check[i] == 0 && M[v][i] == 1)
		{
			DFS(i);
		}
	}
}

void BFS(int v)
{
	check[v] = 1;
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int curV = q.front();
		q.pop();
		cout << curV << " ";
		for (int i = 1; i <= 1000; i++)
		{
			if (check[i] == 0 && M[curV][i] == 1)
			{
				q.push(i);
				check[i] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sv; // start_vertex
	cin >> n >> m >> sv;
	for (int j = 0; j < m; j++)
	{
		int u, v;
		cin >> u >> v;
		M[u][v] = 1;
		M[v][u] = 1;
	}
	DFS(sv);
	cout << '\n';
	memset(check, 0, sizeof(check));
	BFS(sv);
	cout << '\n';

	return 0;
}