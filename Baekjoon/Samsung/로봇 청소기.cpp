#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
int r, c;
int M[51][51];
int check[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int res = 0;
int cnt = 0;
bool end_check = false;

typedef struct info
{
	int x;
	int y;
	int d;
}info;

void DFS(int x, int y, int d)
{
	stack<info> stk;
	stk.push({ x,y,d });
	cnt++;

	while (!stk.empty())
	{
		bool not_check = true;
		info information = stk.top();
		stk.pop();
		
		check[information.x][information.y] = 1;
		vector<int> order;
		if (information.d == 0)
		{
			order.push_back(3);
			order.push_back(2);
			order.push_back(1);
			order.push_back(0);
		}
		else if (information.d == 1)
		{
			order.push_back(0);
			order.push_back(3);
			order.push_back(2);
			order.push_back(1);
		}
		else if (information.d == 2)
		{
			order.push_back(1);
			order.push_back(0);
			order.push_back(3);
			order.push_back(2);
		}
		else if (information.d == 3)
		{
			order.push_back(2);
			order.push_back(1);
			order.push_back(0);
			order.push_back(3);
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[order[i]] + information.x;
			int ny = dy[order[i]] + information.y;
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (M[nx][ny] == 0 && check[nx][ny] == 0)
				{
					cnt++;

					M[nx][ny] = 2;
					stk.push({ nx, ny, order[i] });
					not_check = false;
					break;
				}
			}
		}

		if (not_check == true)
		{
			int temp = information.d;
			switch (information.d)
			{
			case 0:
				information.d = 2;
				break;
			case 1:
				information.d = 3;
				break;
			case 2:
				information.d = 0;
				break;
			case 3:
				information.d = 1;
				break;
			default:
				break;
			}
			int nx = information.x + dx[information.d];
			int ny = information.y + dy[information.d];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && M[nx][ny] != 1)
			{
				stk.push({ nx,ny,temp });
			}
			else
				return;
		}
	}
}

int main()
{
	int d;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 1)
				check[i][j] = -1;
		}
	}
	M[r][c] = 2;
	DFS(r, c, d);
	cout << cnt << endl;

	return 0;
}