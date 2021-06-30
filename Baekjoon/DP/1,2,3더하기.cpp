#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, input, target = 10;
	vector<int> d(11,0);
	cin >> n;
	d[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		d[i] += d[i - 1];
		if (i - 2 >= 0)
			d[i] += d[i - 2];
		if (i - 3 >= 0)
			d[i] += d[i - 3];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cout << d[input] << endl;
	}

	return 0;
}