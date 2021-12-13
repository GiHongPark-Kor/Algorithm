
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100001

bool COMPARE(pair<int, int>a, pair<int, int> b)
{
	return a.first > b.first;
}

vector<int> solution(string sentence)
{
	vector<int> answer;
	vector<pair<int, int>> count(MAX);
	vector<int> temp(MAX, 0);
	for (int i = 0; i < MAX; i++)
	{
		count[i] = make_pair(0, i);
	}
	for (int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == '{' || sentence[i] == '}')
		{
			continue;
		}
		else
		{
			string temp = "";

			while (sentence[i] != ',' && i != sentence.size())
			{
				temp += sentence[i];
				i++;
			}
			count[stoi(temp)].first++;
		}
	}

	sort(count.begin(), count.end(), COMPARE);
	int i = 0;
	while (count[i].first != 0)
	{
		answer.push_back(count[i].second);
		i++;
	}
	return answer;
}