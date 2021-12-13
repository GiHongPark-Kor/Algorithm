#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int v[9];
int c[9];
int ans[9];
int cnt2 = 0;
void BFS(int cnt){

	// exit condition
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << '\n'; // endl 시간초과 발생! 
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
		{
			c[i] = 1;
			ans[cnt] = v[i];
			BFS(cnt + 1);
			c[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v + n);
	BFS(0);
	return 0;
}