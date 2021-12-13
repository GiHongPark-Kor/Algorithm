#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int LeftCurPosition = 10;
	int RightCurPosition = 12;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "L";
			LeftCurPosition = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "R";
			RightCurPosition = numbers[i];
		}
		else
		{
			if (numbers[i] == 0) // 0의 값을 11이라 가정
			{
				numbers[i] = 11;
			}
			int LeftV = abs(numbers[i] - LeftCurPosition) / 3 + abs(numbers[i] - LeftCurPosition) % 3;
			int RightV = abs(numbers[i] - RightCurPosition) / 3 + abs(numbers[i] - RightCurPosition) % 3;
			if (LeftV < RightV)
			{
				answer += "L";
				LeftCurPosition = numbers[i];
			}
			else if (LeftV > RightV)
			{
				answer += "R";
				RightCurPosition = numbers[i];
			}
			else // same
			{
				if (hand == "left")
				{
					answer += "L";
					LeftCurPosition = numbers[i];
				}
				else
				{
					answer += "R";
					RightCurPosition = numbers[i];
				}
			}

		}
	}
	return answer;
}