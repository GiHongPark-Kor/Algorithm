#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int check[20001];
vector<int> adj_list[20001];

bool DFS(int node, int c)
{
	check[node] = c;
	for (int i = 0; i < adj_list[node].size(); i++)
	{
		if (check[adj_list[node][i]] == 0)
		{
			if (DFS(adj_list[node][i], 3 - c) == false)
				return false;
		}
		else if (check[adj_list[node][i]] == c)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TCnum;
	cin >> TCnum;
	bool NoCheck = false;
	for (int i = 0; i < TCnum; i++)
	{
		int Vertex_num, Edge_num;
		cin >> Vertex_num >> Edge_num;
		NoCheck = false;
		for (int j = 1; j <= Vertex_num; j++)
		{
			adj_list[j].clear();
			check[j] = 0;
		}
		for (int j = 0; j < Edge_num; j++)
		{
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);

		}
		for (int j = 1; j <= Vertex_num; j++)
		{
			if (check[j] == 0)
			{
				if (!DFS(j, 1))
				{
					cout << "NO" << '\n';
					NoCheck = true;
					break;
				}
			}
		}
		if (!NoCheck)
			cout << "YES" << '\n';
	}

	return 0;
}