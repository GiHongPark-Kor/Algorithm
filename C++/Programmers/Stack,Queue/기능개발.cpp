#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define TRUE 1
#define FALSE 0
using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int temp, value;
    vector<int> answer;
    queue <int> s;
    for (int i = 0; i < progresses.size(); i++)
    {
        temp = 100 - progresses[i];
        if (temp % speeds[i] == 0)
            value = temp / speeds[i];
        else
        {
            value = (temp / speeds[i]) + 1;
        }
        if (s.empty())
        {
            s.push(value);
        }
        else
        {
            if (s.front() >= value)
                s.push(value);
            else
            {
                answer.push_back(s.size());
                while (!s.empty())
                    s.pop();
                s.push(value);
            }
        }
    }
    if (!s.empty())
        answer.push_back(s.size());
    return answer;
}