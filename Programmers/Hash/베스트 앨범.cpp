#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool COMPARE1(pair<int, int> a, pair<int, int>b) // 속한 노래 정렬 비교함수
{
    return a.second > b.second;
}

bool COMPARE2(pair<string, int>& a, pair<string, int>& b) // 장르별 정렬 비교함수 
{
    return  a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<pair<int, int>>> song; // 속한 노래 정렬
    map<string, int> cnt; // 장르별 정렬
    vector<int> answer;
    
    /* map input */
    for (int i = 0; i < genres.size(); i++)
    {
        song[genres[i]].push_back(make_pair(i, plays[i]));
        cnt[genres[i]] += plays[i];
    }
    
    /* sort */
    map<string, vector<pair<int, int>>>::iterator iter;
    for (iter = song.begin(); iter != song.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end(), COMPARE1);
    }
    vector<pair<string, int>>v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), COMPARE2);


    /* output */
    for (int i = 0; i < v.size(); i++)
    {
        if (song[v[i].first].size() >= 2) {
            answer.push_back(song[v[i].first][0].first);
            answer.push_back(song[v[i].first][1].first);
        }
        else if (song[v[i].first].size() == 1)
            answer.push_back(song[v[i].first][0].first);
        else
            continue;
    }

    return answer;
}