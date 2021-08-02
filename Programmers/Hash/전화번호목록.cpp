#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    unordered_map<string, int> um;
    for (int i = 0; i < phone_book.size(); i++)
    {
        um[phone_book[i]] = 1;
    }
    if (phone_book.size() == 1)
        return true;
    string str;
    for (int i = 0; i < phone_book.size(); i++)
    {
        str = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            str += phone_book[i][j];
            if (um[str] && (str != phone_book[i]))
                return false;
        }
    }
    return answer;
}