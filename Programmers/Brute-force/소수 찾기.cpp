#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int,int> um;
bool isdecimal[10000000]; // 소수 확인
bool check[10000000]; // 중복 확인
int answer; // 결과값 저장

void go(string numbers, int index, int n ,string cur_num)
{
    if(cur_num.size() == n) // exit condition
    {
        if(cur_num != "")
            if (isdecimal[stoi(cur_num)] == false && um.find(stoi(cur_num)) == um.end())
            {
                um[stoi(cur_num)] = index++; 
                answer++;
            }
        return;
    }
    
    for(int i =0; i< numbers.size(); i++)
    {
        if(check[i] == 0)
        {
            check[i] = 1;
            go(numbers, index + 1,n ,cur_num + numbers[i]);    
            check[i] = 0;
        }
    }
}

int solution(string numbers)
{
    //초기화
    int size = pow(10,numbers.size());
    isdecimal[0] = true;
    isdecimal[1] = true;
    
    //소수 찾기
    for (int i = 2; i < size; i++)
    {
        if (isdecimal[i] == true)
            continue;
        else
        {
            for (int j = 2; j < size / i; j++) // 소수 o : false, 소수 x : true
            {
                isdecimal[j * i] = true;
            }
        }
    }
    
    // 소수 확인
    for(int i = 1 ; i<= numbers.size(); i++) // 자리 수마다 소수 check
    {
        go(numbers, 0,i,"");
    }
    
    // 결과 출력
    return answer;
}