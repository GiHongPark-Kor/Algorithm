#include <iostream> // cin, cout
#include <algorithm> //sort
#include <string> // to_string
#include <unordered_map> //stl unordered_map(hash container)
using namespace std;

int n, m;
int v[9];
int output[9];
unordered_map<string, int> um; 

void BFS(int index, int cnt, string cur_string)
{
	//exit condition
	if (cnt == m)
	{
		if (um.find(cur_string) == um.end()) // double check
		{
			for (int i = 0; i < m; i++)
			{
				cout << output[i] << " ";
			}
			cout << endl;
			um[cur_string] = 1;
		}
		return;
	}

	// next step
	for (int i = index; i < n; i++)
	{
		output[cnt] = v[i];
		BFS(i + 1, cnt + 1, cur_string + to_string(v[i]));
	}
}

int main()
{
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	// sort
	sort(v, v + n);

	// BFS function
	BFS(0, 0,"");
	return 0;
}