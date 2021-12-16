# BFS 활용 문제
from collections import deque

def find_near_value(i,j):
    global G
    dq = deque()
    dq.append((i,j))
    while len(dq) != 0:
        (x, y) = dq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < M:
                if G[nx][ny] == 1:
                    G[nx][ny] = 0
                    dq.append((nx, ny))


if __name__ == "__main__":
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    T = int(input())
    for _ in range(T):
        M, N, K = map(int, input().split())

        answer = 0
        G = [[0] * M for _ in range(N)]
        for _ in range(K):
            col, row = map(int, input().split())
            G[row][col] = 1

        for i in range(N):
            for j in range(M):
                if G[i][j] == 1:
                    G[i][j] = 0
                    find_near_value(i, j)
                    answer += 1
        print(answer)

