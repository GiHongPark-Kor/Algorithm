def find(parent, i):
    if parent[i] == i:
        return parent[i]
    else:
        parent[i] = find(parent, parent[i])
        return parent[i]

N = int(input())
M = int(input())
parent = [i for i in range(N + 1)]

for i in range(M):
    s, e = map(int, input().split())

    # UNION & FINE
    s = find(parent,s)
    e = find(parent, e)
    if s < e:
        parent[e] = s
    else:
        parent[s] = e

# print(parent.count(1) - 1) : 오답!!
answer = 0
for i in range(2, N+1):
    if find(parent, i) == 1:
        answer += 1

print(answer)
