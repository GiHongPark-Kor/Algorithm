#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<vector<int>> M(100, vector<int>(100));

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector<vector<int>> func_1()
{
	vector<vector<int>> temp(100, vector<int>(100));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			temp[n - 1 - i][j] = M[i][j];
		}
	}
	return temp;
}

vector<vector<int>> func_2()
{
	vector<vector<int>> temp(100, vector<int>(100));
	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			temp[i][m - 1 - j] = M[i][j];
		}
	}
	return temp;
}

vector<vector<int>> func_3()
{
	vector<vector<int>> temp(100, vector<int>(100));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[j][n - 1 - i] = M[i][j];
		}
	}
	return temp;
}

vector<vector<int>> func_4()
{
	vector<vector<int>> temp(100, vector<int>(100));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[m - 1 - j][i] = M[i][j];
		}
	}
	return temp;
}

vector<vector<int>> func_5()
{
	vector<vector<int>> temp(100, vector<int>(100));
	for (int i = 0; i < n / 2; i++) // 1 -> 2 
	{
		for (int j = 0; j < m / 2; j++)
		{
			temp[i][m / 2 + j] = M[i][j];
		}
	}

	for (int i = 0; i < n / 2; i++) // 2 -> 3 
	{
		for (int j = m / 2; j < m; j++)
		{
			temp[n / 2 + i][j] = M[i][j];
		}
	}

	for (int i = n / 2; i < n; i++) // 3 -> 4 
	{
		for (int j = m / 2; j < m; j++)
		{
			temp[i][j - (m / 2)] = M[i][j];
		}
	}

	for (int i = n / 2; i < n; i++) // 4 -> 1 
	{
		for (int j = 0; j < m / 2; j++)
		{
			temp[i - (n / 2)][j] = M[i][j];
		}
	}
	//cout << (n - 1) - (n / 2) << endl;
	return temp;
}

vector<vector<int>> func_6()
{
	vector<vector<int>> temp(100, vector<int>(100)); 
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			temp[i + n / 2][j] = M[i][j];
			temp[i][j] = M[i][j + m / 2];
			temp[i][j + m / 2] = M[i + n / 2][j + m / 2];
			temp[i + n / 2][j + m / 2] = M[i + n / 2][j];
		}
	}
	return temp;
}


void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		int input_num;
		cin >> input_num;
		switch (input_num)
		{
		case 1:
			M = func_1();
			//print();
			break;

		case 2:
			M = func_2();
			//print();
			break;

		case 3:
			M = func_3();
			swap(&n, &m);
			//print();
			break;

		case 4:
			M = func_4();
			swap(&n, &m);
			//print();
			break;

		case 5:
			M = func_5();
			//print();
			break;

		case 6:
			M = func_6();
			//print();
			break;

		default:
			break;
		}
	}
	print();
	return 0;
}