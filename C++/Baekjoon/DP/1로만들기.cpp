#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min3(int a, int b)
{
	return min(a, b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> d(n + 1, 0);

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			d[i] = min3(min(d[i / 2] + 1, d[i / 3] + 1), d[i - 1] + 1);
		else if (i % 2 == 0)
			d[i] = min(d[i / 2] + 1, d[i - 1] + 1);
		else if (i % 3 == 0)
			d[i] = min(d[i / 3] + 1, d[i - 1] + 1);
		else
			d[i] = d[i - 1] + 1;

	}
	cout << d[n] << '\n';
	return 0;
}