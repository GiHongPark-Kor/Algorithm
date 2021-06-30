#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
char oper[9];
bool check[10];
string v;
vector<string> res;

void func(int index)
{
	if (v.size() == n + 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (oper[i] == '<')
			{
				if (v[i] > v[i + 1])
					return;
			}
			else if (oper[i] == '>')
			{
				if (v[i] < v[i + 1])
					return;
			}
		}
		res.push_back(v);
		return ;
	}
	for (int i = 0; i < 10; i++)
	{
		if (check[i] == false)
		{
			check[i] = true;
			v.push_back((i + '0'));
			func(index + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> oper[i];
	}
	func(0);
	sort(res.begin(), res.end());
	cout << res[res.size() - 1] << endl;
	cout << res[0] << endl;
	
	return 0;
}