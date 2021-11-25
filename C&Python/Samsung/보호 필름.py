min_value = 210000000
T = int(input())
B = [[0] * 14 for i in range(21)]
D = 0
K = 0
W = 0


def TEST(BOARD):
    check = [0] * W
    for i in range(W):
        cnt = 1
        for j in range(1, D, 1):
            if (BOARD[j - 1][i] == BOARD[j][i]):
                cnt += 1
                if (cnt >= K):
                    check[i] = 1
                    break
            else:
                cnt = 1
        if (check[i] == 0):
            return False
    return True


def DFS(BOARD, check, cnt, row):
    global min_value
    if min_value != 210000000 and min_value < cnt:
        return

    if (TEST(BOARD) == True):
        #print(BOARD)
        if min_value > cnt:
            min_value = cnt
            return
    
    # exit condition
    if (row >= D) or (cnt >= D):
        return

    # not A, B
    DFS(BOARD,check, cnt, row + 1)

    # A
    if check[row] == 0:
        backup = [0] * 21
        check[row] = 1
        for i in range(W):
            backup[i] = BOARD[row][i]
            BOARD[row][i] = 0
        DFS(BOARD, check, cnt + 1, row + 1)
        for i in range(W):
            BOARD[row][i] = backup[i]
        check[row] = 0

    # B
    if check[row] == 0:
        backup = [0] * 21
        check[row] = 1
        for i in range(W):
            backup[i] = BOARD[row][i]
            BOARD[row][i] = 1
        DFS(BOARD, check, cnt + 1, row + 1)
        for i in range(W):
            BOARD[row][i] = backup[i]
        check[row] = 0


for test_case in range(1, T + 1):
    check = [0] * 21
    AA, BB, CC = map(int,input().split())
    D = AA
    W = BB
    K = CC
    B = [list(map(int, input().split())) for _ in range(D)]
    if K == 1:
        print("#" + str(test_case) + " 0")
    else:
        DFS(B, check, 0, 0)
        print("#" + str(test_case) + " " + str(min_value))
        min_value = 210000000

