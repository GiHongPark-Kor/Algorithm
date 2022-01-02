#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{ 
	int check[1001];
	int input[101];
	int n;
	int answer = 0;
	memset(check, 0, sizeof(check));
	check[1] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	//에라토스테네스의 체
	for (int i = 2; i * i <= 1000; i++)
	{
		int j = 2;
		while (i * j <= 1000)
		{
			check[i * j] = 1;
			j++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (check[input[i]] == 0)
			answer += 1;
	}

	printf("%d\n", answer);
	return 0;
}