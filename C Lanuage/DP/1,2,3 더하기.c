#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int d[11];
int main() {

	int T, n;
	scanf("%d", &T);
	d[0] = 1;
	
	for (int i = 1; i < 11; i++)
	{
		d[i] += d[i - 1];
		if (i - 2 >= 0)
			d[i] += d[i - 2];
		if (i - 3 >= 0)
			d[i] += d[i - 3];
	}

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d \n", d[n]);
	}

	return 0;
}