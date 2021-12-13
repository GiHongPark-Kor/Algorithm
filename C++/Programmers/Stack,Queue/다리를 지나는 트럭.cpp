#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int check = 0;
    int count;
    int answer = 1;
    int w = truck_weights[0];
    queue <int> q;
    answer += bridge_length;
    q.push(truck_weights[0]);
    for (int i = 1; i < truck_weights.size(); i++)
    {
        if ((w + truck_weights[i]) > weight)
        {
            count = q.size();
            while (!q.empty())
            {
                w -= q.front();
                q.pop();
                count--;
                if ((w + truck_weights[i]) <= weight)
                    break;
            }
            w += truck_weights[i];
            if (check == 2)
            {
                answer += 1;
                check = 0;
            }
            else
            {
                answer += (bridge_length - count);
                check = 2;
            }

            q.push(truck_weights[i]);
        }
        else
        {
            check = 0;
            w += truck_weights[i];
            answer += 1;
            q.push(truck_weights[i]);
        }
    }
    return answer;
}