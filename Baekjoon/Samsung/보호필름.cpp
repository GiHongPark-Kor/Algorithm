#include <iostream>
#include <cstdio>
using namespace std;
int D, W, K;
int check[14]; // A or B 약품 사용여부
pair<int, int> answer = { 1000000000,1000000000 };
bool Test(int Board[14][21]);
void DFS(int v[14][21], int acnt, int bcnt, int row);

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int Board[14][21];
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> Board[i][j];
			
			}
		}
		DFS(Board, 0, 0, 0);
		cout << "#" << test_case << " " << answer.first + answer.second << '\n';

		answer.first = 1000000000;
		answer.second = 1000000000;

	}
	return 0;
}


bool Test(int Board[14][21])
{
	int test_check[21];
	for (int i = 0; i < 21; i++)
		test_check[i] = 0;

	for (int i = 0; i < W; i++)
	{
		int cnt = 1;
		for (int j = 1; j < D; j++)
		{
			if (Board[j - 1][i] == Board[j][i])
			{
				cnt++;
				if (cnt >= K)
				{
					test_check[i] = 1;
					break;
				}
			}
			else
			{
				if (cnt >= K)
				{
					test_check[i] = 1;
					break;
				}
				cnt = 1;
			}
		}

		if (test_check[i] == 0)
			return false;
	}
	for (int i = 0; i < W; i++)
	{
		if (test_check[i] == 0)
			return false;
	}
	return true;
}

void DFS(int v[14][21], int acnt, int bcnt, int row)
{
	/* exit condition */

	if (answer.first != 1000000000 && answer.first + (answer.first + answer.second) < (acnt + bcnt))
		return;

	if (Test(v) == true)
	{
		if ((answer.first + answer.second) > (acnt + bcnt))
		{
			answer.first = acnt;
			answer.second = bcnt;
		}
	}

	if (row >= D)
		return;

	if ((acnt + bcnt) >= D)
	{
		return;
	}

	/* not A, B */
	DFS(v, acnt, bcnt, row + 1);

	/* A */
	if (check[row] == 0)
	{
		int backup[21];
		check[row] = 1;
		for (int i = 0; i < W; i++)
		{
			backup[i] = v[row][i];
			v[row][i] = 0;
		}

		DFS(v, acnt + 1, bcnt, row + 1);

		check[row] = 0;
		for (int i = 0; i < W; i++)
		{
			v[row][i] = backup[i];
		}
	}

	/* B */
	if (check[row] == 0)
	{
		int backup[21];
		check[row] = 1;
		for (int i = 0; i < W; i++)
		{
			backup[i] = v[row][i];
			v[row][i] = 1;
		}

		DFS(v, acnt, bcnt + 1, row + 1);
		check[row] = 0;
		for (int i = 0; i < W; i++)
		{
			v[row][i] = backup[i];
		}
	}
}