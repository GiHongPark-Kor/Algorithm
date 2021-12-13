#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, res = 0;
	cin >> n;
	int start = 1, num = 1;
	string end = "9";
	while (1)
	{
		int cur_end = stoi(end);
		if (cur_end > n)break;
		else
		{
			int cnt = cur_end - start + 1;
			res += num * cnt;
		}
		start *= 10;
		end += "9";
		num++;
	}
	res += (n - start + 1) * num;
	cout << res << endl;
	return 0;
}