#include <iostream>
#include <deque>
using namespace std;

int board[21][21];
int check[21][21];
int answer = -1;
int N;
void init(int backup[21][21]);
void DFS(int cnt);
void up_func();
void down_func();
void left_func();
void right_func();
int find_maxBlcok();

int main()
{
	/* input */

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	/* DFS */
	DFS(0);

	/* output */
	cout << answer << '\n';
	return 0;
}

void DFS(int cnt) {
	int backup[21][21];

	if (cnt == 5) {
		int value = find_maxBlcok();
		if (answer < value)
			answer = value;

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			backup[i][j] = board[i][j];
		}
	}

	left_func();
	DFS(cnt + 1);
	init(backup);

	up_func();
	DFS(cnt + 1);
	init(backup);

	right_func();
	DFS(cnt + 1);
	init(backup);

	down_func();
	DFS(cnt + 1);
	init(backup);
}

int find_maxBlcok()
{
	int temp = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp < board[i][j])
			{
				temp = board[i][j];
			}
		}
	}
	return temp;
}

void init(int backup[21][21])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = backup[i][j];
		}
	}
}

void up_func()
{
	deque<int> q;
	deque<int> res;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[j][i] == 0)
				continue;
			else {
				q.push_back(board[j][i]);
				if (q.size() == 2)
				{
					int a = q.front(); q.pop_front();
					int b = q.front(); q.pop_front();
					if (a == b)
						res.push_back(a + b);
					else
					{
						res.push_back(a);
						q.push_back(b);
					}

				}
			}
		}

		while (q.size() > 0)
		{
			if (q.size() == 2)
			{
				int a = q.front(); q.pop_front();
				int b = q.front(); q.pop_front();
				if (a == b)
					res.push_back(a + b);
				else
				{
					res.push_back(a);
					q.push_back(b);
				}
			}
			else
				res.push_back(q.back()); q.pop_back();
		}

		for (int j = 0; j < N; j++)
		{
			if (res.size() > 0)
			{
				board[j][i] = res.front();
				res.pop_front();
			}
			else
			{
				board[j][i] = 0;
			}
		}
	}
}


void down_func()
{
	deque<int> q;
	deque<int> res;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (board[j][i] == 0)
				continue;
			else {
				q.push_back(board[j][i]);
				if (q.size() == 2)
				{
					int a = q.front(); q.pop_front();
					int b = q.front(); q.pop_front();
					if (a == b)
						res.push_back(a + b);
					else
					{
						res.push_back(a);
						q.push_back(b);
					}

				}
			}
		}

		while (q.size() > 0)
		{
			if (q.size() == 2)
			{
				int a = q.front(); q.pop_front();
				int b = q.front(); q.pop_front();
				if (a == b)
					res.push_back(a + b);
				else
				{
					res.push_back(a);
					q.push_back(b);
				}
			}
			else
				res.push_back(q.back()); q.pop_back();
		}

		for (int j = N - 1; j >= 0; j--)
		{
			if (res.size() > 0)
			{
				board[j][i] = res.front();
				res.pop_front();
			}
			else
			{
				board[j][i] = 0;
			}
		}
	}
}


void left_func()
{
	deque<int> q;
	deque<int> res;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0)
				continue;
			else {
				q.push_back(board[i][j]);
				if (q.size() == 2)
				{
					int a = q.front(); q.pop_front();
					int b = q.front(); q.pop_front();
					if (a == b)
						res.push_back(a + b);
					else
					{
						res.push_back(a);
						q.push_back(b);
					}

				}
			}
		}

		while (q.size() > 0)
		{
			if (q.size() == 2)
			{
				int a = q.front(); q.pop_front();
				int b = q.front(); q.pop_front();
				if (a == b)
					res.push_back(a + b);
				else
				{
					res.push_back(a);
					q.push_back(b);
				}
			}
			else
				res.push_back(q.back()); q.pop_back();
		}

		for (int j = 0; j < N; j++)
		{
			if (res.size() > 0)
			{
				board[i][j] = res.front();
				res.pop_front();
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}
}

void right_func()
{
	deque<int> q;
	deque<int> res;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (board[i][j] == 0)
				continue;
			else {
				q.push_back(board[i][j]);
				if (q.size() == 2)
				{
					int a = q.front(); q.pop_front();
					int b = q.front(); q.pop_front();
					if (a == b)
						res.push_back(a + b);
					else
					{
						res.push_back(a);
						q.push_back(b);
					}

				}
			}
		}

		while (q.size() > 0)
		{
			if (q.size() == 2)
			{
				int a = q.front(); q.pop_front();
				int b = q.front(); q.pop_front();
				if (a == b)
					res.push_back(a + b);
				else
				{
					res.push_back(a);
					q.push_back(b);
				}
			}
			else
				res.push_back(q.back()); q.pop_back();
		}

		for (int j = N - 1; j >= 0; j--)
		{
			if (res.size() > 0)
			{
				board[i][j] = res.front();
				res.pop_front();
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}
}
