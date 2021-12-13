#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> check(51);
vector<int> res;

void dfs(string begin, string target, vector<string>& words, vector<int>& res, int num)
{
    if (begin == target) {
        res.push_back(num);
        return;
    }
    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (check[i] == 0) {
            for (int j = 0; j < begin.size(); j++)
                if (begin[j] == words[i][j] && count != begin.size() - 1)
                    count++;

            if (count == begin.size() - 1) {
                num++; check[i] = 1;
                dfs(words[i], target, words, check, num, res);
                check[i] = 0; num--;
            }
        }
        count = 0;
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int num = 0;

    dfs(begin, target, words, res, num);
    if (res.size() == 0)
    {
        answer = 0;
    }
    else
    {
        sort(res.begin(), res.end());
        answer = res[0];
    }
    return answer;
}