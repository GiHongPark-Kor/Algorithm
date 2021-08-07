#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ary[101];

int FIND_PARENT(int v)
{
    if(ary[v] == v) 
        return ary[v];
    else 
        return FIND_PARENT(ary[v]);
    
}

bool COMPARE(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}


int solution(int n, vector<vector<int>> costs) // kruskal's algorithm
{
    int answer = 0;
    sort(costs.begin(),costs.end(),COMPARE);
    for(int i =0; i<=101; i++) ary[i] = i;
    for(int i = 0; i<costs.size(); i++)
    {
        int a = FIND_PARENT(costs[i][0]);
        int b = FIND_PARENT(costs[i][1]);
        if(a != b) // not cycle
        {
            ary[b] = FIND_PARENT(a); // Union
            answer += costs[i][2];
        }
    }
    return answer;
}