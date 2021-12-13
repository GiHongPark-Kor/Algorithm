// �ٸ� Ǯ�� ����
// next_permutation, DFS�� �����ϸ� �ð��ʰ� �߻�
// (�ٽ� ��) string w �ҹ���, �빮�� ���� vs (index ������Ű��) string s �ҹ��� �빮�� ���� : ���� �� answer++
#include <iostream>
#include <string>
using namespace std;

string W, S;
int wcount, scount;
int answer = 0;
int wdownArr[27];
int wupArr[27];
int sdownArr[27];
int supArr[27];
bool check;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> wcount >> scount;
	cin >> W >> S;
	for (int i = 0; i < wcount; i++)
	{
		if ('a' <= W[i] && W[i] <= 'z')
		{
			wdownArr[(int)(W[i] - 'a')]++;
		}
		else
		{
			wupArr[(int)(W[i] - 'A')]++;
		}
	}

	for (int i = 0; i < scount; i++)
	{
		if (i < wcount)
		{
			if ('a' <= S[i] && S[i] <= 'z')
			{
				sdownArr[(int)(S[i] - 'a')]++;
			}
			else
			{
				supArr[(int)(S[i] - 'A')]++;
			}
		}
		else
		{
			/* �ߺ� ��� ���ϱ� ���� - index : i - wcount ���� && i ���� */
			if ('a' <= S[i - wcount] && S[i - wcount] <= 'z')
			{
				sdownArr[(int)(S[i - wcount] - 'a')]--;
			}
			else
			{
				supArr[(int)(S[i - wcount] - 'A')]--;
			}

			if ('a' <= S[i] && S[i] <= 'z')
			{
				sdownArr[(int)(S[i] - 'a')]++;
			}
			else
			{
				supArr[(int)(S[i] - 'A')]++;
			}
		}


		check = true;
		for (int j = 0; j < 27; j++)
		{
			if (wdownArr[j] != sdownArr[j] || wupArr[j] != supArr[j])
			{
				check = false;
				break;
			}
		}

		if (check == true)
			answer++;

	}
	cout << answer << '\n';

	return 0;
}