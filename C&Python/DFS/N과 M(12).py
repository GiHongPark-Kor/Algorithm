def solution(idx, cnt, temp, d):
    # exit condition
    if cnt == M:
        if ' '.join(temp) not in d:
            d[' '.join(temp)] = 1
            print(' '.join(temp))
        return

    # visit
    for j in range(idx,N,1):
        temp.append(str(arr[j]))
        solution(j,cnt + 1, temp, d)
        temp.pop()


# input
N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
d = {} # 결과 중복출력 방지
solution(0,0,[], d)