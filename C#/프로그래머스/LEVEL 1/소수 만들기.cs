using System;

class Solution
{
    int answer = 0;
    int[] check = new int[3001];

    public void func(int idx, int cnt, int total, int[] arr)
    {
        if (cnt == 3)
        {
            if (check[total] == 0)
            {
                answer += 1;
            }
            return;
        }

        for (int i = idx; i < arr.Length; i++)
        {
            func(i + 1, cnt + 1, total + arr[i], arr);
        }
    }

    public int solution(int[] nums)
    {
        check[0] = 1;
        check[1] = 1;
        
        for (int i = 2; i <= (int)Math.Sqrt(3000) + 1; i++)
        {
            int j = 2;
            while (i * j <= 3000)
            {
                check[i * j] = 1;
                j += 1;
            }
        }
        func(0, 0, 0, nums);
        return answer;
    }
}