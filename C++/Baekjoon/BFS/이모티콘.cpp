// start : 02 : 23
// end : 02 : 50
// 27 min
// memory ÃÊ°ú -> memorization(check array)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Emo
{
	int CB;
	int cur_num;
	int cnt;
}Emo;
int check[2000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s;
	cin >> s;
	queue<Emo> q;
	q.push({0,1,0});
	while (!q.empty())
	{
		Emo e = q.front();
		q.pop();
		if (e.cur_num == s)
		{
			cout << e.cnt << '\n';
			break;
		}
		if (e.CB != 0 && e.cur_num + e.CB <= 2000 &&check[e.cur_num + e.CB] != 1)
		{
			q.push({ e.CB,e.cur_num + e.CB,e.cnt + 1 });
		}
		if (e.cur_num - 1 >= 0 && check[e.cur_num - 1] != 1)
		{
			q.push({ e.CB,e.cur_num - 1,e.cnt + 1 });
		}	
		q.push({e.cur_num,e.cur_num,e.cnt + 1});
		check[e.cur_num] = 1;
	}


	return 0;
}