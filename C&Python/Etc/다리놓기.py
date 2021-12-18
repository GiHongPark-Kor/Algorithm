# 조합 공식 활용
import math

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    res = math.factorial(M) // (math.factorial(N) * math.factorial(M - N))
    print(res)