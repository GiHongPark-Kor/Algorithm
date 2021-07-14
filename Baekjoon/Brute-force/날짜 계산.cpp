// START : 05 : 03
// END : 05 : 10
// 시간복잡도 : 
#include <iostream>
using namespace std;

int main()
{
	int e, s, m;
	int ecount = 1, scount = 1, mcount = 1;
	int res = 1;
	cin >> e >> s >> m;
	while (1)
	{
		if (e == ecount && s == scount && m == mcount)
		{
			break;
		}
		else
		{
			ecount = ecount + 1;
			scount = scount + 1;
			mcount = mcount + 1;
			if (ecount == 16) ecount = 1;
			if (scount == 29) scount = 1;
			if (mcount == 20) mcount = 1;
			res++;
		}
	}

	cout << res << endl; 

	return 0;
}