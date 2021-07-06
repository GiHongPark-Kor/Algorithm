#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Location
{
	int cur_position;
	int sec;
}Location;

int check[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, res = 0;
	cin >> n >> k;

	deque<Location> q;
	q.push_back({ n, 0 });
	while (!q.empty())
	{
		Location loc = q.front();
		q.pop_front();
		check[loc.cur_position] = 1;

		if (loc.cur_position == k)
		{
			res = loc.sec;
			break;
		}
		if (loc.cur_position < k)
		{
			if (loc.cur_position + 1 <= 100000 && check[loc.cur_position + 1] != 1)
			{
				q.push_back({ loc.cur_position + 1, loc.sec + 1 });
			}
			if (loc.cur_position * 2 <= 100000 && check[loc.cur_position * 2] != 1)
			{
				q.push_front({ loc.cur_position * 2, loc.sec });
			}
		}

		if (loc.cur_position - 1 >= 0 && check[loc.cur_position - 1] != 1)
		{
			q.push_back({ loc.cur_position - 1, loc.sec + 1 });
		}
	}

	cout << res << '\n';
	return 0;
}