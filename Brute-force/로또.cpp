#include <iostream>
#include <vector>
using namespace std;
#define MAX 14
vector<int> v(MAX);
vector<int> c(MAX);
void func(int n, int s, int count)
{
	if (s > n)
		return;
	if (count == 6)
	{
		for (int i = 0; i < n; i++)
		{
			if (c[i] != 0)
			{
				cout << v[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	c[s] = 1;
	func(n, s + 1, count + 1);
	c[s] = 0;
	func(n, s + 1, count);
}

int main()
{
	int	n, input;
	do
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		func(n, 0, 0);
		cout << endl;
	} while (n != 0);


	return 0;
}
