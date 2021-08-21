#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int in_degree[10001]; // 선행 관계의 수 저장 배열
int TIME[10001]; // 작업이 걸리는 시간 저장 배열
int CHECK[10001]; // 가장 오래 걸리는 작업 check 배열
vector<int>adj_list[10001]; // 작업 관계 리스트

int main()
{
	/* input */
	int n; // 수행할 작업 수
	int num, jobnum;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		cin >> TIME[i];
		cin >> num; // 선행작업 수
		for (int j = 0; j < num; j++)
		{
			cin >> jobnum;
			adj_list[jobnum].push_back(i);
			in_degree[i]++;
		}
	}


	// start : indegree 0인 부분 push
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (in_degree[i] == 0)
		{
			q.push(i);
			CHECK[i] = TIME[i];
		}
	}

	// indegree 0이 되는 부분 제거 하며 위상 정렬 + 가장 오래 걸리는 시간 check
	int v, t, answer = -1;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		answer = max(answer, t);
		for (int i = 0; i < adj_list[v].size(); i++)
		{
			int k = adj_list[v][i];
			in_degree[k]--;
			CHECK[k] = max(CHECK[k], CHECK[v] + TIME[k]);
			if (in_degree[k] == 0)
				q.push(k);
		}
	}

	// 결과 출력 & 모든 작업을 완료해야 하기 때문에 가장 오래 걸리는 시간을 answer 출력
	for (int i = 1; i <= n; i++)
		if (answer < CHECK[i])
			answer = CHECK[i];
	cout << answer << endl;
	return 0;
}