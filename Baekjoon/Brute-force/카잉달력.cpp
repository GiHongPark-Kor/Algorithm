// start : 05 : 25

#include <iostream>
using namespace std;

int main()
{
	int t;
	int n, m, x, y;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;
		bool check = false;
		for (int j = x; j <= n * m; j += m)
		{
			if (j % n  == y)
			{
				cout << j + 1 << endl;
				check = true;
				break;
			}
		}

		if (check == false)
		{
			cout << -1 << endl;
		}


	}
	return 0;
}