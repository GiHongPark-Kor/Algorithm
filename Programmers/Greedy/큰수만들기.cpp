#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    int size = number.size() - k;
    int index = -1;
    for(int i =0; i<size; i++)
    {
        char temp = '/';
        for(int j = index + 1; j < k + i + 1; j++)
        {
            if(number[j] > temp)
            {
                temp = number[j];
                index = j;
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}