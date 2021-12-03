def solution(idx, cnt, arr):
    if idx > N:
        return

    if cnt == M:
        print(' '.join(arr))
        return

    # visit
    arr.append(str(idx))
    solution(idx, cnt + 1, arr)
    arr.pop()

    # not visit
    solution(idx + 1, cnt, arr)

N, M = map(int, input().split())
solution(1,0,[])