#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][101];
int c[101][101];
int solution(int m, int n, vector<vector<int>> puddles) 
{
    // dp[1][1] = 1로 초기화 하기 위해 dp[0][1] = 1 or dp[1][0] = 1로 초기화
    dp[0][1] = 1;
    
    // 물 잠긴 지역 check 배열에 넣기
    for(int i = 0; i< puddles.size(); i++)
    {
        c[puddles[i][0]][puddles[i][1]] = 1;
    }
    
    // dp[j][i] = (왼쪽에서 온 경로 + 위쪽에서 온 경로)
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(c[j][i] != 1)
                dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 1000000007;
        }
         
    }
    
    // (m,n) 지역의 최단경로 return
    return dp[m][n];
}