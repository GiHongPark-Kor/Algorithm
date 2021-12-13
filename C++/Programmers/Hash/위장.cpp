#include string
#include vector
#include map
#include iostream
using namespace std;

int solution(vectorvectorstring clothes) {
    int answer = 1;
    mapstring,int m;
    for(int i =0; i  clothes.size(); i++)
    {
        m[clothes[i][1]] += 1;
    }
    for(int i =0; i  clothes.size(); i++)
    {
        answer = (m[clothes[i][1]] + 1);
        m[clothes[i][1]] = 0;
    }
    return answer - 1;
}