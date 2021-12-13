#include string
#include vector
#include iostream
using namespace std;

int solution(vectorvectorint triangle)
{
    int answer = 0;
    for (int i = triangle.size() - 1; i  0; i--)
    {
        for (int j = 0; j  i; j++)
        {
            if (triangle[i - 1][j] + triangle[i][j]  triangle[i-1][j] + triangle[i][j + 1])
            {
                triangle[i - 1][j] +=  triangle[i][j + 1];
            }
            else
            {
                triangle[i - 1][j] += triangle[i][j];
            }
        }
    }
    answer = triangle[0][0];
    return answer;
}