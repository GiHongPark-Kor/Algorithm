
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, B, C;
	int* v;
	long long res = 0; // 범위 조심!
	cin >> N;
	v = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		// 각 시험장 총 감독관 check
		if (B >= v[i])
		{
			res += 1;
			v[i] = 0;
			continue;
		}
		else
		{
			res += 1;
			v[i] -= B;
		}

		// 각 시험장 부 감독관 check
		res += (v[i] / C);
		if ((v[i] % C) != 0)
			res += 1;
	}

	cout << res;

	return 0;
}