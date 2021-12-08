def solution(i, cnt, temp, d):
    # exit condition
    if cnt == M and ' '.join(temp) not in d:
        d[' '.join(temp)] = 1
        print(' '.join(temp))
        return

    if i >= N:
        return

    # visit
    temp.append(str(arr[i]))
    solution(i + 1,cnt + 1, temp, d)
    temp.pop()

    # not visit
    solution(i + 1, cnt, temp, d)

# input
N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
d = {} # 결과 중복출력 방지
solution(0, 0,[], d)