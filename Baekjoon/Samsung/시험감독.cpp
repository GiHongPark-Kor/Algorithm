//start : 02 : 40
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int N, B, C;
	int* v;
	float res = 0;
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

	cout << res << endl;


	return 0;
}