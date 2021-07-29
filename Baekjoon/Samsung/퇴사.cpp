// start : 03 : 05
// end : 03 : 20

#include <iostream>
#include <vector>
using namespace std;
int N, cur_max;
vector<int>T(16);
vector<int>P(16);
vector<int>check(16);

void function(int index, int total)
{
	//exit condition
	if (index > N)
	{
		if (total > cur_max)
			cur_max = total;
		return;
	}
	
	//select
	if(index + T[index] - 1 <= N)
		function(index + T[index], total + P[index]);

	//not select
	function(index + 1, total);

}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	function(1,0);

	cout << cur_max << '\n';
	return 0;
}