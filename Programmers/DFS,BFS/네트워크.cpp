#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> net(201);

void UNION(int a, int b)
{
    net[b] = a;
    return;
}

int FIND(int v)
{
    if(net[v] == -1)
    {
        return v;
    }else
        return FIND(net[v]);
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for(int i =0; i< 201; i++) // 초기화 할 때 net[i] = i로 하면 안된다!
        net[i] = -1;
    
    for(int i =0; i< computers.size(); i++)         
        for(int j =0; j< computers[i].size(); j++)
            if(i != j && computers[i][j] != 0)
            {
                int a = FIND(i);
                int b = FIND(j);
                if(a != b)
                    UNION(a,b);        
            }
    
    for(int i =0; i< n; i++)
    {
        if(net[i] == -1)
            answer++;
    }

    return answer;
}