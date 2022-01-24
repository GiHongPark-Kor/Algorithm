using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    static int N, M;
    static int[] check = new int[10];
    static List<string> answer = new List<string>();
    public static void DFS(int cnt)
    {
        // exit conditon
        if (cnt == M)
        {
            Console.WriteLine(string.Join(' ', answer));
            return;
        }


        for (int i = 1; i <= N; i++)
        {
            // visit
            if (check[i] == 0)
            {
                check[i] = 1;
                answer.Add(i.ToString());
                DFS(cnt + 1);
                answer.RemoveAt(answer.Count - 1);
                check[i] = 0;
            }
        }
    }

    public static void Main()
    {
        string input = Console.ReadLine();
        string[] sinput = input.Split(' ');

        for (int i = 0; i < 10; i++)
            check[i] = 0;

        N = int.Parse(sinput[0]);
        M = int.Parse(sinput[1]);
        DFS(0);
    }
}