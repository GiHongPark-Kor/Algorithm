#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 12
vector<int> number(MAX);
vector<int> oper(4);
int MV = INT_MAX;
int LV = INT_MIN;
void func(int sum, int plus, int min, int mul, int div, int index)
{
	if (plus == min && min == mul && mul== div && div== 0)
	{
		if(MV > sum)
		{
			MV = sum;
		}

		if (LV < sum)
		{
			LV = sum;
		}
		return ;
	}
	if (plus > 0)
	{
		func(sum + number[index], plus - 1, min, mul, div, index + 1);
	}

	if (min > 0)
	{
		func(sum - number[index], plus, min - 1, mul, div, index + 1);
	}

	if (mul > 0)
	{
		func(sum * number[index], plus, min, mul - 1, div, index + 1);
	}

	if (div > 0)
	{
		func(sum / number[index], plus, min, mul, div - 1, index + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	func(number[0], oper[0], oper[1], oper[2], oper[3],1);
	cout << LV << endl;
	cout << MV << endl;

	return 0;
}
