#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string comb;

int SIZE;
int answer;
void go(int index, char beforeType ,int before)
{
	if (index == SIZE)
	{
		answer++;
		return;
	}

	if (comb.at(index) == 'd')
	{
		for (int j = 0; j < 10; j++)
		{
			if (beforeType == 'd' && before == j)
				continue;
			go(index + 1, 'd', j);
		}
	}
	else if (comb.at(index) == 'c')
	{
		for (int j = 0; j < 26; j++)
		{
			if (beforeType == 'c' && before == j)
				continue;
			go(index + 1, 'c', j);
		}
	}
}

int main()
{
	cin >> comb;
	SIZE = comb.size();

	go(0,'0',-1);
	cout << answer << endl;
	return 0;
}