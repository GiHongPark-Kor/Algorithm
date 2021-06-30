#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> alpha(26,0);
bool COMPARE(int a, int b)
{
	return a > b;
}

int main()
{
	int n, size;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		size = v[i].size();
		int num = 1;
		for (int j = size - 1; j >= 0; j--)
		{
			alpha[v[i].at(j) - 'A'] += num;
			num *= 10;
		}
	}
	sort(alpha.begin(),alpha.end(),COMPARE);
	int w = 9;
	int res = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] != 0)
		{
			res += w * alpha[i];
			w--;
		}
		else
			break;
	}
	cout << res << endl;
	return 0;
}