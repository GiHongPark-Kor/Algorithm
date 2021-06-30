#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	vector<int> DP(n + 1, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	DP[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= v[i]; j++)
		{
			if (i + j < n)
			{
				if (DP[i + j] == -1)
				{
					if (v[i + j] != 0 && DP[i] != -1)
						DP[i + j] = DP[i] + 1;
				}

			}
			else
				break;
		}
	}
	cout << DP[n - 1] << endl;

	return 0;
}