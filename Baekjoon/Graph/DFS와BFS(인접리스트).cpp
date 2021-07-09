#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int check[1001];
vector<int> adj_list[1001];

void DFS(int v)
{
	check[v] = 1;
	cout << v << " ";
	for (int i = 0; i < adj_list[v].size(); i++)
	{
		if (check[adj_list[v][i]] != 1)
		{
			DFS(adj_list[v][i]);
		}
	}
}


void BFS(int v)
{
	queue<int> q;
	q.push(v);
	check[v] = 1;
	while (!q.empty())
	{
		int curV = q.front();
		q.pop();
		cout << curV << " ";
		for (int i = 0; i < adj_list[curV].size(); i++)
		{
			if (check[adj_list[curV][i]] != 1)
			{
				check[adj_list[curV][i]] = 1;
				q.push(adj_list[curV][i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int vnum, edgnum, start_v;
	cin >> vnum >> edgnum >> start_v;
	for (int i = 0; i < edgnum; i++)
	{
		int u, v;
		cin >> u >> v;
		/*양방향*/
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);

	}
	
	for (int i = 1; i <= vnum; i++)
	{
		sort(adj_list[i].begin(),adj_list[i].end());
	}

	/*DFS*/
	DFS(start_v); 
	cout << '\n';

	/*초기화*/
	memset(check, 0, sizeof(check));

	/*BFS*/
	BFS(start_v);
	cout << '\n';

	return 0;
}