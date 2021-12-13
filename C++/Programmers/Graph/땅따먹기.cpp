#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001


int solution(vector<vector<int> > land)
{
    int answer = 0;
    int a, b;
    int temp;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            temp = -1;
            for (int k = 0; k < land[i - 1].size(); k++)
            {
                if (j != k && temp < land[i - 1][k])
                {
                    temp = land[i - 1][k];
                }
            }
            land[i][j] = temp + land[i][j];
        }
    }
    sort(land[land.size() - 1].begin(), land[land.size() - 1].end());
    answer = land[land.size() - 1][3];
    return answer;
}