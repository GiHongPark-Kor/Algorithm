#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 26
int solution(string s)
{
	if (s.size() == 1)
		return 0;

	stack<char> stk;
	stk.push(s.at(0));
	for (int i = 1; i < s.size(); i++)
	{
		if (stk.empty())
			stk.push(s.at(i));
		else if (stk.top() == s.at(i))
			stk.pop();
		else
			stk.push(s.at(i));
	}

	if (stk.size() == 0)
		return 1;
	else
		return 0;
}