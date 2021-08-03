#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> c(31);

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] += 1;
    }
    for (int i = 0; i < lost.size(); i++)
    {
        c[lost[i]] -= 1;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        c[reserve[i]] += 1;
    }
    for (int i = 0; i < lost.size(); i++)
    {
        if (c[lost[i]] == 0 && c[lost[i] - 1] == 2)
        {
            c[lost[i]]++;
            c[lost[i] - 1]--;
            continue;
        }

        if (c[lost[i]] == 0 && c[lost[i] + 1] == 2)
        {
            c[lost[i]]++;
            c[lost[i] + 1]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > 0)
            answer++;
    }
    return answer;
}