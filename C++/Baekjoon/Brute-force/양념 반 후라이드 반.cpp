#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int answer = 2100000000;
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	for (int i = 0; i <= 100000; i++)
	{
		if (X - i < 0 && Y - i < 0)
			break;
		else if (X - i < 0)
			answer = min(answer, (2 * i) * C + (Y - i) * B);
		else if( Y - i < 0)
			answer = min(answer, (2 * i) * C + (X - i) * A);
		else
			answer = min(answer, (2 * i) * C + (X - i) * A + (Y - i) * B);	
	}
	cout << answer << endl;
	return 0;
}