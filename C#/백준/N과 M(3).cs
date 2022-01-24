using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution
{
    static StringBuilder stringBuilder = new StringBuilder();
    static int N, M;
    static List<int> answer = new List<int>();

    public static void DFS(int cnt)
    {
        if (cnt == M)
        {
            for (int i = 0; i < answer.Count; i++)
            {
                stringBuilder.Append(answer[i] + " ");
            }
            stringBuilder.Append("\n");
            return;
        }

        for (int i = 1; i <= N; i++)
        {
            answer.Add(i);
            DFS(cnt + 1);
            answer.RemoveAt(answer.Count - 1);
        }

    }

    public static void Main()
    {
        string input_data = Console.ReadLine();
        string[] split_data = input_data.Split(' ');
        N = int.Parse(split_data[0]);
        M = int.Parse(split_data[1]);
        DFS(0);
        Console.Write(stringBuilder.ToString());
    }
}