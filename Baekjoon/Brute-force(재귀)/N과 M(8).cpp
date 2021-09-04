#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int v[9]; // input data array
int c[9]; // output data array

void BFS(int index, int cnt)
{
	//exit condition
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << c[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (index >= n)
		return;

	// input data
	c[cnt] = v[index];
	BFS(index, cnt + 1);

	// not input data
	BFS(index + 1, cnt);

}

int main()
{
	//initialization
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	//sort
	sort(v, v + n);
	
	//function
	BFS(0, 0);
	return 0;
}