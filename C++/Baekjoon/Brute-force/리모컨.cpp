// start : 10 : 40
// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int check[10];

bool func(int i)
{
	while (i)
	{
		if (check[i % 10] == 0)
		{
			i /= 10;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	//input process
	int n, m;
	int input;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		check[input] = 1;
	}

	// initial value =  only + or - 
	int res = abs(n - 100);

	if (check[0] == 0)
	{
		int num = to_string(0).size();
		if (res > abs(n) + num)
		{
			res = abs(n) + num;
		}
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (func(i))
		{	
			int num = to_string(i).size();
			if (res > abs(n - i) + num)
			{
				//cout << i << " " << abs(n - i) + num<<endl;
				res = abs(n - i) + num;
			}
		}
	}
	cout << res << endl;

	return 0;
}