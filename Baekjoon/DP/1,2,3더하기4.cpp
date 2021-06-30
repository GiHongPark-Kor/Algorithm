#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, input, target = 10000;
	vector<int> d(10001,0);
	int num[3] = { 1,2,3 };
	cin >> n;
	d[0] = 1;
	for (int j = 0; j <= 2; j++)
		for (int i = 1; i <= target; i++)
		{
			if(i - num[j] >= 0)
				d[i] += d[i - num[j]];
		}
	
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cout << d[input] << endl;
	}

	return 0;
}