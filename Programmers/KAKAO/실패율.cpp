#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<pair<double, int>> vmap;
    vector<int> cnt(N + 2, 0);
    vector<int> answer(N);
    for (int i = 0; i < stages.size(); i++)
    {
        cnt[stages[i]]++;
    }
    double denominator = (double)stages.size();

    for (int i = 0; i < N; i++)
    {
        if (denominator != 0)
        {
            double temp = (cnt[i + 1] / denominator);
            vmap.push_back(make_pair(temp, i + 1));
            denominator -= cnt[i + 1];
        }
        else
            vmap.push_back(make_pair(0, i + 1));
    }
    int index = N - 1;
    sort(vmap.begin(), vmap.end(), cmp);
    for (auto iter = vmap.begin(); iter != vmap.end(); iter++)
    {

        //cout << iter->first << ", " << iter->second << endl;
        //cout << endl;

        if (iter->second != N + 1)
        {
            answer[index--] = iter->second;
        }
    }
    return answer;
}