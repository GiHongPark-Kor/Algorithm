#include <iostream>
using namespace std;
int n, m;
int v[10];

void solution(int index, int start)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++)
	{
		v[index] = i;
		solution(index+1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	solution(0,1);

	return 0;
}