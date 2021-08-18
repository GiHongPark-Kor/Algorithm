#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;
    sort(times.begin(),times.end());
    long long s = 1;
    long long e = (long long) times[times.size() - 1] * n;
    while(s <= e)
    {
        long long mid = (s + e) / 2; 
        long long cnt = 0;
        for(int i =0; i< times.size(); i++)
        {
            cnt += mid / times[i];
        }
        
        if(cnt < n)
        {
            s = mid + 1;
        }else
        {
            answer = mid;
            e = mid - 1;
        }
        
    }
    
    return answer;
}