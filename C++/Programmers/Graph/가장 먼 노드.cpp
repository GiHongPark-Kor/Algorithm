#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool COMPARE(int a, int b)
{
    return a > b;    
}
void bfs(vector<list<int>> &List, vector<int> &count, int n)
{
    int cnt = 0;
    vector<int> visit(n+1,0);
    int temp;
    queue<int> q;
    q.push(1);
    visit[1] = 1; count[1] = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop(); 
        cnt++;
        for(auto iter = List[temp].begin();iter != List[temp].end(); iter++)
        {
            if(visit[*iter] != 1)
            {
                q.push(*iter);
                visit[*iter] = 1;
                count[*iter] = count[temp] + 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    int v1,v2;
    vector<int> count(n+1,0);
    vector<list<int>> List(n + 1);
    
    for(int i = 0; i<edge.size(); i++)
    {
        v1 = edge[i][0];
        v2 = edge[i][1];
        List[v1].push_back(v2);
        List[v2].push_back(v1);
    }
    bfs(List,count, n);
    sort(count.begin(),count.end(),COMPARE);
    int temp = *(count.begin());
    for(auto iter = count.begin() + 1; iter != count.end(); iter++)
    {
        if(temp == *iter)
            answer++;
        else
            break;
    }
    return answer;
}