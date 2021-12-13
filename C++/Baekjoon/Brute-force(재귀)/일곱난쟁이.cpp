#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[9];
bool check = false;
vector<int> v;
vector<int> res;

void func(int sum, int i)
{
	if (sum == 100 && v.size() == 7)
	{
		res = v;
		check = true;
		return;
	}

	if (i >= 9 || check == true)
		return;

	sum += input[i];
	v.push_back(input[i]);
	func(sum, i + 1);

	sum -= input[i];
	v.pop_back();
	func(sum, i + 1);

}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> input[i];
	}
	func(0, 0);
	sort(res.begin(), res.end());
	for (int i = 0; i < 7; i++)
	{
		cout << res[i] << '\n';
	}

	return 0;
}