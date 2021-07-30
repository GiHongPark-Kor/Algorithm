#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    int I,J,K;
    for(int i =0; i<commands.size(); i++)
    {
        vector<int> temp;
        I = commands[i][0];
        J = commands[i][1];
        K = commands[i][2];
        temp.assign(array.begin() + I - 1, array.begin() + J);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[K - 1]);
    }
    return answer;
}