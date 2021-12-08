def solution(cnt, temp, check, d):
    # exit condition
    if cnt == M and ' '.join(temp) not in d:
        d[' '.join(temp)] = 1
        print(' '.join(temp))
        return


    for i in range(N):
        if check[i] == 0:    # visit
            check[i] = 1
            temp.append(str(arr[i]))
            solution(cnt + 1, temp, check, d)
            temp.pop()
            check[i] = 0

# input
N, M = map(int, input().split())
arr = list(map(int,input().split()))
arr.sort()
check = [0] * len(arr) # 수열안 중복된 수 삽입 방지
d = {} # 결과 중복출력 방지
solution(0,[], check, d)