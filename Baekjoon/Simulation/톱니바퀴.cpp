#include <iostream>
#include <string.h>
using namespace std;

int C[5][9];

void rotation(int n, int d)
{
	if (d == -1)
	{
		int temp = C[n][1];
		for (int i = 2; i <= 8; i++)
		{
			C[n][i - 1] = C[n][i];
		}
		C[n][8] = temp;
	}
	else
	{
		//int temp = C[n][8];
		//for (int i = 1; i <= 7; i++)
		//{
		//	C[n][i + 1] = C[n][i];
		//}
		//C[n][1] = temp;

		int temp = C[n][8];
		for (int i = 7; i >= 1; i--)
		{
			C[n][i + 1] = C[n][i];
		}
		C[n][1] = temp;
	}
}

void Left(int cur, int left, int d)
{
	if (left < 1)
		return;
	if (C[cur][7] != C[left][3])
	{
		Left(cur - 1, left - 1, -d);
		rotation(left, -d);
	}
	else
		return;
}

void Right(int cur, int right, int d)
{
	if (right > 4)
		return;
	if (C[cur][3] != C[right][7])
	{
		Right(cur + 1, right + 1, -d);
		rotation(right, -d);
	}
	else
		return;
}

void print()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= 8; j++)
		{
			C[i][j] = str.at(j - 1) - '0';
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n, d;
		cin >> n >> d;
		Left(n, n - 1, d);
		Right(n, n + 1, d);
		rotation(n, d);
	/*	print();
		cout << endl;
	*/
	}

	int res = 0;
	int tmp = 1;
	for (int i = 1; i <= 4; i++)
	{
		//cout << "c : " << i << " : "<< C[i][1] << endl;
		if (C[i][1] == 0)
			res += 0;
		else
		{
			res += tmp;
		}
		tmp *= 2;
	}
	cout << res << endl;
	return 0;
}