#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int index = 0;
    int cur_time = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq; // min heap
    sort(jobs.begin(), jobs.end()); 
    while(!pq.empty() || index < jobs.size())
    {
        if(index < jobs.size() && cur_time >= jobs[index][0])
        {
            pq.push(make_pair(jobs[index][0],jobs[index][1]));
            index++;
            continue;
        }
        
        if(!pq.empty())
        {
            cur_time += pq.top().second;
            answer += cur_time - pq.top().first;
            pq.pop();
        }else
        {
            cur_time = jobs[index][0];
        }
        
    }
    return answer / jobs.size();
}