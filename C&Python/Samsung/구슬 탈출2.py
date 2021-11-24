N, M = input().split()
N = int(N)
M = int(M)
G = []
dx = [0,1,0,-1]
dy = [-1,0,1,0]
check = [[0] * 11 for i in range(11)]
answer = 2100000000
Tx = 0
Ty = 0

def DFS(rx,ry,bx,by,cnt,before):
    global  answer
    if cnt > 10:
        return

    for i in range(4):
        if before == i:
            continue
        Rx = rx
        Ry = ry
        Bx = bx
        By = by
        while True:
            if (check[Rx + dx[i]][Ry + dy[i]] == 1) or (Rx == Tx and Ry == Ty):
                break
            else:
                Rx += dx[i]
                Ry += dy[i]

        while True:
            if ((check[Bx + dx[i]][By + dy[i]] == 1) or (Bx == Tx and By == Ty)):
                break;
            else:
                Bx += dx[i]
                By += dy[i]

        if (Rx == Bx and Ry == By):
            if (Rx == Tx and Ry == Ty):
                continue
            else:
                if i == 0:
                    if (ry < by):
                        By -= dy[i]
                    else:
                        Ry -= dy[i]
                elif (i == 1):
                    if (rx < bx):
                        Rx -= dx[i]
                    else:
                        Bx -= dx[i]
                elif (i == 2):
                    if (ry < by):
                        Ry -= dy[i]
                    else:
                        By -= dy[i]
                elif (i == 3):
                    if (rx < bx):
                        Bx -= dx[i]
                    else:
                        Rx -= dx[i]
            DFS(Rx, Ry, Bx, By, cnt + 1, i)
        else:
            if (Rx == Tx and Ry == Ty):
                if answer > cnt:
                    answer = cnt
                return
            elif (Bx == Tx and By == Ty):
                continue
            else:
                DFS(Rx, Ry, Bx, By, cnt + 1, i)


#input
for i in range(N):
    str = input()
    G.append(str)

for i in range(N):
    for j in range(M):
        if G[i][j] == 'O':
            Tx = i
            Ty = j
        elif G[i][j] == 'B':
            bx = i
            by = j
        elif G[i][j] == 'R':
            rx = i
            ry = j
        elif G[i][j] == '#':
            check[i][j] = 1
        else:
            continue

# for i in range(N):
#     for j in range(M):
#         print(check[i][j], end=" ")
#     print()

DFS(rx, ry, bx, by, 1,100);

if answer == 2100000000:
    print(-1)
else:
    print(answer)
