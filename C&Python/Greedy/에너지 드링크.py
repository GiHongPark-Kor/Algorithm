from collections import deque
N = int(input())
arr = list(map(int, input().split()))
arr.sort()
dq = deque(arr)
#print(type(dq))
for i in range(N - 1):
    v1 = dq.popleft()
    v2 = dq.pop() + v1 / 2
    dq.append(v2)

print(dq.pop())