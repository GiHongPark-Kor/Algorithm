#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    stack<int> s;
    int answer = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size() ; j++)
        {
            if (board[j][col] == 0)
            {
                continue;
            }
            else
            {
                if (!s.empty())
                {
                    if (s.top() == board[j][col])
                    {
                        s.pop();
                        answer += 2;
                    }
                    else
                        s.push(board[j][col]);
                }
                else
                {
                    s.push(board[j][col]);
                }
                board[j][col] = 0;
                break;
            }
        }
    }
    return answer;
}