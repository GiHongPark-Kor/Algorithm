from collections import deque
import sys
input = sys.stdin.readline

def topology_sort(N, input_data, adj_list, value_list):
	global answer
	dq = deque()
	for i in range(1, N + 1):
		if indegree[i] == 0:
			dq.append((i, value_list[i]))
	temp = [0] * (N + 1) # 핵심 : 같은 level에 있는 값 중 max 값 찾기 위해 필요
	while dq:
		v, c = dq.popleft()
		answer = max(answer, c)
		for i in range(len(adj_list[v])):
			indegree[adj_list[v][i]] -= 1
			temp[adj_list[v][i]] = max(c + value_list[adj_list[v][i]], temp[adj_list[v][i]])
			if indegree[adj_list[v][i]] == 0:
				dq.append((adj_list[v][i], temp[adj_list[v][i]]))

#input 및 초기화				
answer = 0
adj_list = []
N =int(input())
indegree = [0] * (N + 1)
value_list = [0] * (N + 1)
input_data = [list(map(int,input().split())) for _ in range(N)]

for i in range(N + 1):
	adj_list.append([])

for i in range(1, N + 1):
	value_list[i] = input_data[i - 1][0]
	for j in range(input_data[i-1][1]):
		adj_list[input_data[i - 1][j + 2]].append(i)
		indegree[i] += 1

topology_sort(N, input_data, adj_list, value_list)
print(answer)