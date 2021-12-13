#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[9];
int c[9];
int n, m;

void BFS(int index, int cnt)
{
	/* output */
	if (cnt == m)
	{
		for (int i = 0; i < n; i++)
		{
			if(c[i] == 1)
				cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	/* exit condition */
	if (index == n)
		return;

	c[index] = 1;
	BFS(index + 1, cnt + 1);
	
	c[index] = 0;
	BFS(index + 1, cnt);

}


int main()
{
	/* input */
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v, v + n);
	BFS(0,0);

	return 0;
}