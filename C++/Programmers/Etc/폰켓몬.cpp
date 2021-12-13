#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int count = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i + 1])
            count++;
    }
    if (nums.size() / 2 >= count)
    {
        return count;
    }
    else if (nums.size() / 2 < count)
        return nums.size() / 2;


}