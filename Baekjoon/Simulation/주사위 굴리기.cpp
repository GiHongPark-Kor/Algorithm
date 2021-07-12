#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M[21][21];
int D[] = { 0,0,0,0,0,0,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, x, y, cmdN;
	cin >> n >> m >> x >> y >> cmdN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
		}
	}

	for (int i = 0; i < cmdN; i++)
	{
		int input;
		cin >> input;
		switch (input)
		{
		case 4: // ��
			if (x + 1 < n)
			{
				// �ֻ��� ��ȭ
				int temp = D[1];
				D[1] = D[5];
				D[5] = D[6];
				D[6] = D[2];
				D[2] = temp;


				if (M[x + 1][y] == 0)
				{
					M[x + 1][y] = D[1];
				}
				else
				{
					D[1] = M[x + 1][y];
					M[x + 1][y] = 0;
				}
				cout << D[6] << '\n';
				x = x + 1;
			}
			break;
		case 3: // ��
			if (x - 1 >= 0)
			{
				// �ֻ��� ��ȭ
				int temp = D[1];
				D[1] = D[2];
				D[2] = D[6];
				D[6] = D[5];
				D[5] = temp;


				if (M[x - 1][y] == 0)
				{
					M[x - 1][y] = D[1];
				}
				else
				{
					D[1] = M[x - 1][y];
					M[x - 1][y] = 0;
				}
				cout << D[6] << '\n';
				x = x - 1;
			}
			break;
		case 2: // ��
			if (y - 1 >= 0)
			{

				// �ֻ��� ��ȭ
				int temp = D[1];
				D[1] = D[4];
				D[4] = D[6];
				D[6] = D[3];
				D[3] = temp;

				if (M[x][y - 1] == 0)
				{
					M[x][y - 1] = D[1];
				}
				else
				{
					D[1] = M[x][y - 1];
					M[x][y - 1] = 0;
				}
				cout << D[6] << '\n';
				y = y - 1;
			}
			break;
		case 1: // ��
			if (y + 1 < m)
			{
				// �ֻ��� ��ȭ
				int temp = D[1];
				D[1] = D[3];
				D[3] = D[6];
				D[6] = D[4];
				D[4] = temp;

				if (M[x][y + 1] == 0)
				{
					M[x][y + 1] = D[1];
				}
				else
				{
					D[1] = M[x][y + 1];
					M[x][y + 1] = 0;
				}
				cout << D[6] << '\n';
				y = y + 1;
			}
			break;
		default:
			break;
		}
		//for (int i = 1; i <= 6; i++)
		//	cout << D[i] << " ";
		//cout << '\n';
	}


	return 0;
}