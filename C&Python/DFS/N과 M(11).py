def solution(cnt, temp, d):
    # exit condition
    if cnt == M:
        if ' '.join(temp) not in d:
            d[' '.join(temp)] = 1
            print(' '.join(temp))
        return

    # visit
    for j in range(N):
        temp.append(str(arr[j]))
        solution(cnt + 1, temp, d)
        temp.pop()


# input
N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
d = {} # 결과 중복출력 방지
solution(0,[], d)