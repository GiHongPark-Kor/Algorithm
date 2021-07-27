#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check[10];
int n, m;
vector<int> v(10);
void solution(int index)
{
	// exit condition
	if (m == index)
	{
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}


	for (int i = 1; i <= n; i++)
	{
		if (check[i] != 1)
		{
			check[i] = 1;
			v[index] = i;
			solution(index + 1);
			check[i] = 0;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	solution(0);

	return 0;
}