
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;
	vector<vector<int>>table1(n, vector<int>(n, 0));
	vector<vector<int>>table2(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++) // bitmask 
		{
			if (arr1[j] & (1 << i))
			{
				table1[j][n - 1 - i] = 1;
			}
			if (arr2[j] & (1 << i))
			{
				table2[j][n - 1 - i] = 1;
			}
		}
	for (int j = 0; j < n; j++)
	{
		string s = "";
		for (int i = 0; i < n; i++) // check 
		{
			if (table1[j][i] == 1 || table2[j][i] == 1)
			{
				s += "#";
				table1[j][i] = 1;
			}
			else
			{
				s += " ";
			}
		}
		answer.push_back(s);
	}
	return answer;
}