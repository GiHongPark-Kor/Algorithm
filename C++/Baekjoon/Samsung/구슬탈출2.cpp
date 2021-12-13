#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string G[11];
int check[11][11];
int N, M, Tx, Ty;;
int dx[] = { 0, 1, 0, -1 }; // 왼, 밑, 오, 위
int dy[] = { -1, 0, 1, 0 };
int answer = 2100000000;

bool is_target(int x, int y)
{
	if (x == Tx && y == Ty)
		return true;
	else
		return false;
}

void DFS(int rx, int ry, int bx, int by, int cnt, int before)
{
	//exit condition
	if (cnt > 10)
		return;

	for (int i = 0; i < 4; i++)
	{
		int Rx = rx;
		int Ry = ry;
		int Bx = bx;
		int By = by;

		// 빨간 구슬 동작
		while (1)
		{
			if ((check[Rx + dx[i]][Ry + dy[i]] == 1) || (Rx == Tx && Ry == Ty)) //벽이거나 구멍에 들어가면 종료
			{
				break;
			}
			else
			{
				Rx += dx[i];
				Ry += dy[i];
			}
		}
		// 파란 구슬 동작
		while (1)
		{
			if ((check[Bx + dx[i]][By + dy[i]] == 1) || (Bx == Tx && By == Ty)) //벽이거나 구멍에 들어가면 종료
			{
				break;
			}
			else
			{
				Bx += dx[i];
				By += dy[i];
			}
		}

		if (Rx == Bx && Ry == By)
		{
			if (Rx == Tx && Ry == Ty) {
				continue;
			}
			else // 겹칠 경우 처리
			{
				if (i == 0){
					if (ry < by)
						By -= dy[i];
					else
						Ry -= dy[i];
				}else if (i == 1){
					if (rx < bx)
						Rx -= dx[i];
					else
						Bx -= dx[i];
				}
				else if (i == 2){
					if (ry < by)
						Ry -= dy[i];
					else
						By -= dy[i];
				}
				else if (i == 3){
					if (rx < bx)
						Bx -= dx[i];
					else
						Rx -= dx[i];
				}
				DFS(Rx, Ry, Bx, By, cnt + 1, i);
			}	
		}
		else{
			if (Rx == Tx && Ry == Ty){ // 빨간 구슬만 들어갔을 경우
				if (answer > cnt)
					answer = cnt;
				return;
			}
			else if (Bx == Tx && By == Ty){ // 파란 구슬만 들어갔을 경우
				continue;
			}else{
				DFS(Rx, Ry, Bx, By, cnt + 1, i); // 다음 동작
			}
		}

	}

}


int main()
{
	int rx, ry, bx, by;

	/* input */
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> G[i];
	}

	/* init */
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (G[i][j] == 'O'){
				Tx = i;
				Ty = j;
			}
			else if (G[i][j] == 'B'){
				bx = i;
				by = j;
			}
			else if (G[i][j] == 'R'){
				rx = i;
				ry = j;
			}
			else if (G[i][j] == '#'){
				check[i][j] = 1;
			}
			else
				continue;
		}
	}

	DFS(rx, ry, bx, by, 1,100);

	if (answer == 2100000000){
		cout << -1 << endl;
	}else
		cout << answer << endl;
	return 0;
}