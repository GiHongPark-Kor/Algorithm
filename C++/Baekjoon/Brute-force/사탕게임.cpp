#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
char B[51][51];

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int check(int r, int r2, int c1, int c2)
{
	// row 검사
	int cur_max = -1;
	for (int i = r; i <= r2; i++)
	{
		int temp = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (B[i][j] == B[i][j + 1])
			{
				temp++;
			}
			else
			{
				if (cur_max < temp)
					cur_max = temp;
				temp = 1;
			}
		}
		if (cur_max < temp)
			cur_max = temp;

	}

	// col 검사
	for (int i = c1; i <= c2; i++)
	{
		int temp = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (B[j][i] == B[j + 1][i])
			{
				temp++;
			}
			else
			{
				if (cur_max < temp)
					cur_max = temp;
				temp = 1;
			}
		}
		if (cur_max < temp)
			cur_max = temp;
	}
	//cout << cur_max << endl;
	return cur_max;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> B[i][j];
		}
	}

	// initial max value
	int cur_max = check(0,n-1,0,n-1);
	
	// 좌우 swap
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (B[i][j] != B[i][j + 1])
			{
				swap(B[i][j], B[i][j + 1]);
				int value = check(i, i, j, j + 1);
				if (cur_max < value)
					cur_max = value;
				swap(B[i][j], B[i][j + 1]);
			}
			else
				continue;
			
		}
	}

	// 상하 swap
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (B[j][i] != B[j + 1][i])
			{
				swap(B[j][i], B[j + 1][i]);
				int value = check(j, j + 1, i, i);
				if (cur_max < value)
					cur_max = value;
				swap(B[j][i], B[j + 1][i]);
			}
			else
				continue;

		}
	}

	cout << cur_max << endl;

	return 0;
}