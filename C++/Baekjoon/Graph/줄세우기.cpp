#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int in_degree[32001];
//int out_degree[32001];
int main()
{
	//DAG 구현(BFS 활용)
	int n, m; // n : 학생 수, m : 비교 횟수
	int a, b; // a, b : 학생
	queue<int> q;
	cin >> n >> m;
	
	//인접리스트 정의
	vector<int> adj_list[32001];

	// input 과정
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		//out_degree[a]++;
		in_degree[b]++;
		adj_list[a].push_back(b);
	}

	// start : indegree 0인 부분 push
	for (int i = 1; i <= n; i++)
	{
		if (in_degree[i] == 0)
		{
			q.push(i);
		}
	}

	// indegree 0이 되는 부분 제거 하며 위상 정렬
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 0; i < adj_list[v].size(); i++)
		{
			int k = adj_list[v][i];
			in_degree[k]--;
			if (in_degree[k] == 0)
				q.push(k);
		}
	}
	cout << endl;
	return 0;
}