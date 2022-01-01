import sys
def dfs(arr, cnt, N, K, num):
    # exit condition
    if cnt == K:
        global dic
        global answer
        if num not in dic:
            dic[num] = 1
            answer += 1
        return

    for i in range(N):
        if check[i] == 0: # visit
            check[i] = 1
            dfs(arr, cnt + 1, N, K, num + str(arr[i]))
            check[i] = 0



if __name__ == "__main__":
    # init
    arr = []
    dic = {}
    answer = 0

    # input
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    for i in range(N):
        temp = int(sys.stdin.readline())
        arr.append(temp)

    # solution
    check = [0] * N
    dfs(arr, 0, N, K, "")

    # output
    print(answer)
