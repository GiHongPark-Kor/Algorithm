def solution(cnt, temp):
    if cnt == M:
        print(' '.join(temp))
        return

    for i in range(len(arr)):
        if check[i] == 0:
            temp.append(str(arr[i]))
            check[i] = 1
            solution(cnt + 1, temp)
            check[i] = 0
            temp.pop()

N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
check = [0] * N
solution(0,[])
