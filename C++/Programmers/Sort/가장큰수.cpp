#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) 
{
    return to_string(a) + to_string(b) < to_string(b) + to_string(a);
}   

string solution(vector<int> numbers) {

    string answer = "";
    if (numbers.size() == 1)
        return answer + to_string(numbers[0]);
    sort(numbers.begin(), numbers.end(),compare);
    string pre = to_string(numbers[0]);
    for (int i = 1; i < numbers.size(); i++)
    {

        if (pre + to_string(numbers[i]) < to_string(numbers[i]) + pre)
        {
            answer = to_string(numbers[i]) + pre;
            pre = to_string(numbers[i]) + pre;
        }
        else
        {
            answer = pre + to_string(numbers[i]);
            pre = pre + to_string(numbers[i]);
        }
    }
    if(numbers[numbers.size()-1] == 0)
        return to_string(0);
    
    return answer;
}