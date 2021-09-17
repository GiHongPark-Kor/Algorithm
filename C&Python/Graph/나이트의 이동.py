from collections import deque

dx = [-2, -1, +1, +2, -2, -1, +1, +2]
dy = [-1, -2, -2, -1, +1, +2, +2, +1]
m = [[0] * 301 for i in range(301)]


def solution(x, y, w, z, I):
    queue = deque()
    queue.append((x, y, 0))
    m[x][y] = 1
    while queue:
        x, y, c = queue.popleft()
        for j in range(8):
            nx = dx[j] + x
            ny = dy[j] + y
            if 0 <= nx < I and 0 <= ny < I:
                if nx == w and ny == z:
                    m[nx][ny] = 1
                    return c + 1
                else:
                    if m[nx][ny] == 0:
                        m[nx][ny] = 1
                        queue.append((nx, ny, c + 1))
    return -1


n = int(input())
for i in range(n):
    I = int(input())
    for j in range(I):
        for k in range(I):
            m[j][k] = 0
    x, y = map(int, input().split())
    w, z = map(int, input().split())
    if x == w and y == z:
        print(0)
    else:
        res = solution(x, y, w, z, I)
        print(res)
