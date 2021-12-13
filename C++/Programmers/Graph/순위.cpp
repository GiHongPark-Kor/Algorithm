#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    vector<vector<bool>> check(n + 1,vector<bool>(n + 1,false)); 
    for(int i =0; i< results.size(); i++)
    {
        check[results[i][0]][results[i][1]] = true;   
    }
        
    /*floyd warshall*/
    // 거쳐가는 정점
    for(int k=1; k<=n; k++)
    {
        // 시작 정점
        for(int i=1; i<=n; i++)
        {
            // 끝 정점
            for(int j=1; j<=n; j++)
            {
                if(check[i][k] && check[k][j])
                {
                    check[i][j] = true;
                }
            }

        }
    }
    
    for(int i =1; i<=n; i++)
    {
        int cnt = 0;
        for(int j = 1; j<=n; j++)
        {
            if(check[i][j] || check[j][i])
                cnt++;    
        }
        if(cnt == n - 1)
        {
            answer++;
        }
    }
    return answer;
}