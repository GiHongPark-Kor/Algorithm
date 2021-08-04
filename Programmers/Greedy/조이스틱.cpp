#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[27] = { false };

int count_cur_position(char Alpha)
{
    if (abs(Alpha - 'A') < abs('Z' - Alpha) + 1)
        return abs(Alpha - 'A');
    
    else
        return abs('Z' - Alpha) + 1;
}

int solution(string name) 
{
    int answer = 0;
    int left = name.size() - 1, right = 1, cur_position;
    int c1 = 0, c2 = 0, p1, p2;

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
        {
            check[i] = true;
        }
    }

    for (int i = name.size(); i <= 26; i++)
    {
        check[i] = true;
    }
    answer += count_cur_position(name.at(0));
    cur_position = 0;
    check[0] = true;
    
    do
    {
        c1 = 1; c2 = 1;
        p1 = cur_position - 1;
        if (cur_position == 0)
            p1 = name.size() - 1;
       
        p2 = cur_position + 1;
        if (cur_position == name.size() - 1)
            p2 = 0;

        while (p1 != cur_position)
        {
            if (check[p1] == true)
            {
                c1++;
                if (p1 == 0)
                    p1 = name.size() - 1;
                else
                    p1--;
            }
            else
            {
                break;
            }
        }

        while (p2 != cur_position)
        {
            if (check[p2] == true)
            {
                c2++;
                if (p2 == name.size() - 1)
                    p2 = 0;
                else
                    p2++;
            }
            else
            {
                break;
            }
        }

        if (p1 == cur_position)
            c1 = 210000000;

        if (p2 == cur_position)
            c2 = 210000000;
        
        if (p1 == cur_position && p2 == cur_position)
            break;

        if (c1 < c2)
        {
            answer += c1;
            answer += count_cur_position(name.at(p1));
            cur_position = p1;
            check[cur_position] = true;
            //cout << answer << endl;
        }
        else
        {
            answer += c2;
            answer += count_cur_position(name.at(p2));
            cur_position = p2;
            check[cur_position] = true;
            //cout << answer << endl;
        }

    } while (p1 != p2);
    return answer;
}