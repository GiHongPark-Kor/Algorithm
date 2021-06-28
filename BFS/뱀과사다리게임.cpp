#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int _next[101];
int check[101];
int main()
{
	int n, m;
	int x,y;

	cin >> n >> m;
	for (int i = 0; i < 101; i++)
	{
		_next[i] = i;
		check[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		_next[x] = y;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		_next[x] = y;
	}

	queue<int> q;
	q.push(1);
	check[1] = 0;
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int next = value + i;
			if (next > 100) break;
			next = _next[next];
			if (check[next] == -1)
			{
				check[next] = check[value] + 1;
				q.push(next);
			}
		}
	}
	cout << check[100] << endl;
	
	return 0;

}