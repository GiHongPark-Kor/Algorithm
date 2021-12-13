#include <string>
#include <vector>

using namespace std;

vector<int> num;
int tar, answer;

void go(int index, int sum)
{
    if(index == num.size())
    {
        if(sum == tar)
            answer++;
        return;
    }
    go(index + 1, sum + num[index]); 
    go(index + 1, sum - num[index]);
    
}

int solution(vector<int> numbers, int target) 
{
    num = numbers;
    tar = target;
    go(0,0);
    return answer;
}