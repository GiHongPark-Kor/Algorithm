#include <string>
#include <math.h>
#include <vector>
using namespace std;

int solution(string dartResult)
{
	int answer = 0;
	int cnt = 0;
	int loopcnt = 0;
    vector<int>round(3,0);
    
	for (int i = 0; i < dartResult.size(); i = i + loopcnt)
	{
		int v = 0;
		loopcnt = 0;
		if ( 0 <= dartResult[i] - '0' && dartResult[i] - '0' <= 9)
		{
			int temp;
			if (dartResult[i] - '0' == 1 && dartResult[i + 1] - '0' == 0){
				temp = 10;
				i++;
			}
			else{
				temp = dartResult[i] - '0';
            }
            
			if (dartResult[i + 1] == 'S'){
				v = pow(temp, 1);
			}
			else if (dartResult[i + 1] == 'D'){
				v = pow(temp, 2);
			}
			else if (dartResult[i + 1] == 'T'){
				v = pow(temp, 3);
			}
			loopcnt += 2;
		}
        
		if (i + 2 < dartResult.size() && (dartResult[i+2] == '*' || dartResult[i + 2] == '#'))
        {
			if (dartResult[i + 2] == '*'){
				if(cnt == 0)
					v *= 2;
				else{
					round[cnt - 1] *= 2;
					v *= 2;
				}
			}
			else{
				v = -v;
			}
			loopcnt++;
		}
		round[cnt++] = v;
	}
	answer = round[0] + round[1] + round[2];
	return answer;
}