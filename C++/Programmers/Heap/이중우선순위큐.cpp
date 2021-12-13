#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;
struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

struct compare2
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int, vector<int>, compare> minH; // min heap
    priority_queue<int, vector<int>, compare2> maxH; // min heap
    int InumCheck = 0;
    int DnumCheck = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i].at(0) == 'I')
        {
            if (InumCheck == DnumCheck)
            {
                priority_queue<int, vector<int>, compare> empty2;
                swap(minH, empty2);
                priority_queue<int, vector<int>, compare2> empty1;
                swap(maxH, empty1);
            }
            int index = 2;
            int sign = +1;
            if (operations[i].at(2) == '-')
            {
                sign = -1;
                index++;
            }
            string str = "";

            while (index < operations[i].size())
            {
                str += operations[i].at(index);
                index++;
            }
            int value = stoi(str);
            if (sign == -1)
                value = -value;
            minH.push(value);
            maxH.push(value);
            InumCheck++;
        }
        else if (operations[i].at(0) == 'D')
        {
            if (InumCheck == DnumCheck)
            {
                continue;
            }
            else if (InumCheck > DnumCheck)
            {
                if (operations[i].at(2) == '1')
                {
                    maxH.pop();
                }
                else if (operations[i].at(2) == '-')
                {
                    minH.pop();
                }
                DnumCheck++;
            }
        }
    }
    if (InumCheck == DnumCheck)
    {
        answer.push_back(0);
        answer.push_back(0);
        //cout << "1" << endl;
        return answer;
    }
    else if (InumCheck - DnumCheck == 1)
    {
        unordered_map<int, int> um;
        while (maxH.size() != 0)
        {
            um[maxH.top()] = 1;
            maxH.pop();
        }
        while (minH.size() != 0)
        {
            if (um[minH.top()] == 1)
                break;
            else
                minH.pop();

        }
        answer.push_back(minH.top());
        answer.push_back(minH.top());
        return answer;
    }
    else
    {
        answer.push_back(maxH.top());
        answer.push_back(minH.top());
        //cout << "4 " << minH.size() << " " << maxH.size() << endl;
        return answer;
    }
}