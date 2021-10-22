# 위상정렬 코드 구현
# DAG : 사이클이 존재하지 않는 방향 그래프
from collections import deque
import sys
input = sys.stdin.readline

def topology_sort():
	result = []
	q = deque()
	# 진입차수 0인 애들 큐에 삽입
	for i in range(1, v+1):
		if indegree[i] == 0:
			q.append(i)

	# 큐에 들어온 순서대로 정렬
	while q:
		now = q.popleft()
		result.append(now)
		# 현재 진입차수가 0인 정점에 연결된 간선의 정점들 진입차수 -1
		for i in graph[now]:
			indegree[i] -= 1
			# 0이되면 큐에 삽입
			if indegree[i] == 0:
				q.append(i)

	# 결과 값 출력
	for i in result:
		print(i, end=' ')

# 입력 초기화
v, e = map(int, input().split())
indegree = [0] * (v + 1)
graph = [[] for i in range(v + 1)]

# 간선 추가, 받는 입장 -> 진입차수 증가
for _ in range(e):
	a, b = map(int, input().split())
	graph[a].append(b)
	indegree[b] += 1

topology_sort()

#input
# 7 8
# 1 2
# 1 5
# 2 3
# 2 6
# 3 4
# 4 7
# 5 6
# 6 4

# output : 1 2 5 3 6 4 7