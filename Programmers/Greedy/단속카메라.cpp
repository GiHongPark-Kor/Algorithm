#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool COMPARE(vector<int> a, vector<int> b)
{
    return a[0] < b[0];    
}

int solution(vector<vector<int>> routes) 
{
    int s,e;
    int answer = 1;
    sort(routes.begin(),routes.end(),COMPARE);
    s = routes[0][0]; e = routes[0][1];
    for(int i =1; i<routes.size(); i++)
    {
        if(s <= routes[i][0] && routes[i][0] <= e)
        {
            s = routes[i][0];
            if(e >= routes[i][1])
                e = routes[i][1];
        }else
        {
            answer +=1;
            s = routes[i][0];
            e = routes[i][1];
        }
    }
    return answer;
}