from collections import deque

def bfs(vertex, check, num, adj_list):
    dq = deque()
    dq.append(vertex)
    check[vertex] = 1
    while len(dq) != 0:
        v = dq.popleft()
        print(v, end=" ")
        for idx in adj_list[v]:
            if check[idx] == 0:
                check[idx] = 1
                dq.append(idx)


def dfs(vertex, check, num, adj_list):
    check[vertex] = 1
    print(vertex, end=" ")
    for idx in adj_list[vertex]:
        if check[idx] == 0:
            dfs(idx, check, num, adj_list)

# 입력 & adj_list 생성
n, m, v = map(int, input().split())
adj_list = []
for i in range(n + 1):
    adj_list.append(([]))

for i in range(m):
    x, y = map(int, input().split())
    adj_list[x].append(y)
    adj_list[y].append(x)

for i in range(n+1):
    adj_list[i].sort()
check = [0] * (n + 1)
dfs(v, check, n, adj_list)
print(end='\n')

check = [0] * (n + 1)
bfs(v, check, n, adj_list)
print(end='\n')