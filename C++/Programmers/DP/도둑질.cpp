#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) 
{
    int answer = 0;
    vector<int> DP_1(money.size(),money[0]); // 첫 번째 집부터
    vector<int> DP_2(money.size(),money[1]); // 두 번째 집부터
    DP_2[0]= 0;
    for(int i =2; i<money.size() - 1; i++)
    {
        DP_1[i] = max(DP_1[i - 1], DP_1[i - 2] + money[i]);
    }
    for(int i =2; i<money.size(); i++)
    {
        DP_2[i] = max(DP_2[i - 1], DP_2[i - 2] + money[i]);
    }
    
    
   return max(DP_1[money.size() - 2], DP_2[money.size() -1]);
}