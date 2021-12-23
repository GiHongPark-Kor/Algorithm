from collections import deque
# 상, 하, 좌, 우, 오위, 오아, 왼위, 왼아
dx = [-1,1,0,0,-1,1,-1,1]
dy = [0,0,-1,1,1,1,-1,-1]
w = 0
h = 0

def dfs(arr, x, y):
    dq = deque()
    dq.append((x, y))
    arr[x][y] = 0
    while len(dq) != 0:
        x, y = dq.popleft()
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if arr[nx][ny] == 1:
                    arr[nx][ny]= 0
                    dq.append((nx,ny))

def count_island(arr):
    cnt = 0
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == 1:
                dfs(arr, i, j)
                cnt += 1
    return cnt

if __name__ == "__main__":
    while True:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break
        arr = []
        for i in range(h):
            temp = list(map(int,input().split()))
            arr.append(temp)
        res = count_island(arr)
        print(res)


