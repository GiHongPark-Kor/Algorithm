#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool COMPARE(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}
vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> m1 = { 1, 2, 3, 4, 5 };
    vector<int> m2 = { 2,1,2,3,2,4,2,5 };
    vector<int> m3 = { 3,3,1,1,2,2,4,4,5,5 };
    vector<pair<int, int>> c;
    c.push_back(make_pair(0, 1));
    c.push_back(make_pair(0, 2));
    c.push_back(make_pair(0, 3));

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == m1[i % 5])
            c[0].first++;

        if (answers[i] == m2[i % 8])
            c[1].first++;

        if (answers[i] == m3[i % 10])
            c[2].first++;
    }
    sort(c.begin(), c.end(), COMPARE);
    answer.push_back(c[0].second);
    for(int i =1; i< 3; i++)
    {
        if(c[i - 1].first == c[i].first)
            answer.push_back(c[i].second);
        else
            break;
    }
        
    return answer;
}