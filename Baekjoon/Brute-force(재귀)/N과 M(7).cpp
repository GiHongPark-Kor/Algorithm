#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int v[8];
int res[8];
void BFS(int cnt)
{
	//exit condition
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		res[cnt] = v[i];
		BFS(cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v, v + n);
	BFS(0);

	return 0;
}
