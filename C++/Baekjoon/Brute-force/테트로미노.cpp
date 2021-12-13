#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dx[19][4] = { 
		{0,0,1,1},
		{0,1,2,3},
		{0,0,0,0},
		{0,0,1,2},
		{0,0,1,2},
		{0,1,2,2},
		{0,1,2,2},
		{0,0,0,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,1,1,1},
		{0,1,1,2},
		{0,1,1,2},
		{0,0,1,1},
		{0,0,1,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,1,1,2},
		{0,1,1,2}
	};
	
	int dy[19][4] = { 
		{0,1,0,1},
		{0,0,0,0},
		{0,1,2,3},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,1},
		{0,0,0,-1},
		{0,1,2,0},
		{0,1,2,2},
		{0,0,1,2},
		{0,0,-1,-2},
		{0,0,1,1},
		{0,0,-1,-1},
		{0,1,0,-1},
		{0,-1,0,1},
		{0,1,2,1},
		{0,-1,0,1},
		{0,0,1,0},
		{0,-1,0,0}
	};
	bool check = true;
	int M[500][500];
	int n, m, max_value = 0; // n : 세로, m : 가로
	cin >> n >> m;
	
	for(int i =0; i< n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int t = 0; t < 19; t++)
			{
				int temp = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[t][k];
					int ny = j + dy[t][k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						temp += M[nx][ny];
					}
					else
					{
						check = false;
						break;
					}
				}
				if (check == true)
				{
					if (temp > max_value)
						max_value = temp;
				}
				check = true;
			}
		}
	}

	cout << max_value << '\n';
	return 0;
}