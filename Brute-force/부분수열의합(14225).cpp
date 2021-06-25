// bool ¹è¿­ »ç¿ëÇÏ±â!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 20

vector<int> ans;
vector<int> v(MAX);

void func(int n, int sum, int index)
{
	if (index == n)
	{
		if(sum !=0)
			ans.push_back(sum);
		return;
	}
	func(n, sum + v[index],index + 1);
	func(n, sum,index + 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	func(n, 0,0);
	sort(ans.begin(), ans.end());
	if (ans[0] != 1)
	{
		cout << "1" << endl;
		return 0;
	}

	for (int i =1; i<ans.size(); i++)
	{
		if (ans[i - 1] == ans[i])
		{
			continue;
		}
		else if (ans[i - 1] + 1 != ans[i])
		{
			cout << ans[i - 1] + 1 << endl;
			return 0;
		}
		else if (ans[i - 1] + 1 == ans[i])
			continue;
			
	}
	cout << ans[ans.size() - 1] + 1 << endl;
	
	
	return 0;
}
