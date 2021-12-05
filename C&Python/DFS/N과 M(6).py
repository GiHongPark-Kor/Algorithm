def solution(idx, cnt, temp):
    if cnt == M:
        print(' '.join(temp))
        return

    if idx >= N:
        return

    # visit
    temp.append(str(arr[idx]))
    solution(idx+1, cnt + 1, temp)
    temp.pop()

    # not visit
    solution(idx+1, cnt, temp)

N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
solution(0,0,[])
