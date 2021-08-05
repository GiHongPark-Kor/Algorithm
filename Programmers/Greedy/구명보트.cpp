#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    int p1 = 0, p2 = people.size() - 1;
    sort(people.begin(),people.end());
    while(p1 < p2)
    {
        if(people[p1] + people[p2] <= limit)
        {
            p1++;
            p2--;
            answer++;
        }else
        {
            p2--;
            answer++;
        }
    }
    if(p1 == p2)
        answer++;
    return answer;
}