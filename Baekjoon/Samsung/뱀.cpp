#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int M[100][100]; // 0 : �ʱⰪ, 1 : ���, 2 : ���� ��
int d = 0; // 0 : right, 1 : down, 2 : left, 3 : up
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int res;
int N, K, r, c;
vector<pair<int, char>> v;
int cnt = 0;
bool endcheck = false;
queue<pair<int, int>> q;
void func(int curRow, int curCol, int sec)
{
	// exit condition
	if (curRow < 1 || curRow > N || curCol < 1 || curCol > N || M[curRow][curCol] == 2)
	{
		res = sec;
		endcheck = true;
		return;
	}

	// ��� check �� ���� ���� ���
	if (M[curRow][curCol] == 1)
	{
		M[curRow][curCol] = 2;
		q.push(make_pair(curRow, curCol));
	}
	else
	{
		if (!q.empty())
		{
			pair<int, int> pa = q.front();
			q.pop();
			M[pa.first][pa.second] = 0;
			q.push(make_pair(curRow, curCol));
			M[curRow][curCol] = 2;
		}
	}

	// ���� ��ȯ 
	if (cnt < v.size() && sec == v[cnt].first)
	{
		if (v[cnt].second == 'L')
		{
			d -= 1;
			if (d == -1)
				d = 3;
		}
		else
		{
			d = (d + 1) % 4;
		}
		cnt++;
	}
	

	// ���� ����
	if(endcheck == false)
		func(curRow + dx[d], curCol + dy[d], sec + 1);

}

int main()
{
	// input
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		M[r][c] = 1;
	}

	int L, sec;
	char ch;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> sec >> ch;
		v.push_back(make_pair(sec, ch));
	}

	// solve
	q.push(make_pair(1,1));
	func(1,1,0);

	// output
	cout << res << '\n';

	return 0;
}