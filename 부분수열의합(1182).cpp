#include <iostream>
#include <vector>
using namespace std;
#define MAX 20
vector<int> v(MAX);

int ans;


void func(int n, int index, int target, int sum)
{
	if (index == n)
	{
		if (sum == target)
		{
			ans++;
		}
		return;
	}
	
	
	func(n,index + 1,target,sum + v[index]);
	func(n, index + 1, target, sum);

}

int main()
{
	int n, S;
	cin >> n >> S;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	func(n,0, S,0);
	if (S == 0) ans -= 1;
	cout << ans << endl;
	return 0;
}