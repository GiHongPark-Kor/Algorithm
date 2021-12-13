#include <string>
#include <vector>
using namespace std;

// size의 약수의 곱들을 다 해본다. 가로 및 세로는 최소 3이 되어야 한다!
vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int size= brown+yellow;
    for(int i =(brown + yellow) / 2; i>=3; i--)
    {
        if(size % i == 0)
        {
            int j = size / i;
            if((i - 2) * (j - 2) == yellow)
            {
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
        
    }
    
    return answer;
}