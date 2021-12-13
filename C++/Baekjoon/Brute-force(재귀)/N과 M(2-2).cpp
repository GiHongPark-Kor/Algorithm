//#include <iostream>
//using namespace std;
//
//int check[10];
//int n, m;
//
//void solution(int k, int cnt)
//{
//	if (k > n)
//	{
//		if (cnt == m)
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				if (check[i] == 1)
//					cout << i << " ";
//			}
//			cout << '\n';
//		}
//		return ;
//	}
//	check[k] = 1;
//	solution(k + 1, cnt + 1);
//	check[k] = 0;
//	solution(k + 1, cnt);
//
//}
//
//int main()
//{
//	cin >> n >> m;
//	solution(1,0);
//	return 0;
//}