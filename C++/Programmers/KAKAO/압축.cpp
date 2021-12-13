#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> um;
vector<int> solution(string msg)
{
    int check = 0;
    int index = 27;
    char ch;
    string str, before;
    vector<int> answer;
    for (int i = 1; i <= 26; i++)
    {
        ch = 'A' + (i - 1);
        str = "";
        str += ch;
        um.insert(make_pair(str, i));
    }

    for (int i = 0; i < msg.size() - 1; i++)
    {
        str = ""; before = ""; ch;
        while (i < msg.size())
        {
            ch = msg.at(i);
            str += ch;
            if (um.find(str) == um.end())
            {
                answer.push_back(um[before]);
                check = 1;
                break;
            }
            else
            {
                i++;
                before = str;
            }

        }
        if (check == 1)
        {
            check = 0;
            i--;
        }
        else // 문자열이 딱 맞게 떨어진 경우
        {
            check = 2;
            answer.push_back(um[before]);
        }

        if (i > msg.size() - 1)
            break;
        um.insert(make_pair(str, index++));
    }

    if (check != 2) // 문자열 맨 마지막 문자를 넣어줘야 하는 경우
    {
        str = "";
        ch = msg[msg.size() - 1];
        str += ch;
        answer.push_back(um[str]);
    }


    return answer;
}