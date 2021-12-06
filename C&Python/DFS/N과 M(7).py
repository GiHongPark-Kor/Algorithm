def solution(cnt, temp):
    if cnt == M:
        print(' '.join(temp))
        return

    # visit
    for i in range(N):
        temp.append(str(arr[i]))
        solution(cnt + 1, temp)
        temp.pop()

N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
solution(0,[])
