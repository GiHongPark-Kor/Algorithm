#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector <int> order = priorities;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		pair <int, int> temp;
		temp = make_pair(priorities[i], i);
		q.push(temp);
	}
	sort(order.begin(), order.end(), cmp);
	vector<int> ::iterator iter;
	iter = order.begin();
	while (!q.empty())
	{
		if (q.front().first < *iter)
		{
			q.push(q.front());
			q.pop();
		}
		else
		{
			if (q.front().second == location)
			{
				answer++;
				break;
			}
			else
			{
				q.pop();
				answer++;
			}
			iter++;
		}
	}
	return answer;
}