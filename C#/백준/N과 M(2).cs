using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    static int N, M;
    static List<int> answer = new List<int>();

    public static void DFS(int cnt,int idx, int []check)
    {
        // exit conditon
        if (idx > N)
            return;

        if (cnt == M)
        {
            //출력
            for (int i = 0; i < M; i++)
            {
                Console.Write(answer[i]);
                Console.Write(" ");
            }
            Console.WriteLine();
            return;
        }

        // visit
        if (check[idx] == 0)
        {
            check[idx] = 1;
            answer.Add(idx);
            DFS(cnt + 1, idx, check);
            answer.RemoveAt(answer.Count - 1);
            check[idx] = 0;
        }

        // not visit
        DFS(cnt, idx + 1, check);
    }

    public static void Main()
    {
        string input = Console.ReadLine();
        string [] sinput = input.Split(' ');
        int[] check = new int[10];

        for (int i = 0; i < 10; i++)
            check[i] = 0;
        N = int.Parse(sinput[0]);
        M = int.Parse(sinput[1]);
        DFS(0, 1, check);
    }
}