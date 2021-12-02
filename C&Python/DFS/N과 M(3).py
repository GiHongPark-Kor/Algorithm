def solution(cnt, temp):
    # exit condition
    if cnt == M:
        print(' '.join(temp))
        return

    for i in range(1,N + 1):
        temp.append(str(i))
        solution(cnt + 1, temp)
        temp.pop()

N, M = map(int,input().split())
solution(0, [])