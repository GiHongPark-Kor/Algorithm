from collections import deque
N = int(input())
arr = list(map(int, input().split()))
arr.sort()
answer = 0
dq = deque(arr)

while (len(dq) != 0) and (len(dq) != 1):
    v1 = dq.popleft()
    v2 = dq.pop()
    answer += v2 * 2

if len(dq) == 1:
    answer += dq.pop()

print(answer)