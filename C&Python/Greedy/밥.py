# input
N , X = map(int, input().split())
arr = []
for i in range(N):
    a, b = map(int, input().split())
    arr.append([a, b])

# sort : 차이가 가장 작은 순으로 정렬 : 가성비가 가장 좋은 5000원을 선택한다.
arr = sorted(arr, key = lambda x : abs(x[0] - x[1]), reverse = True)
answer = 0


# calculate
for i in range(N):
    # 현재 남은 개수 * 가격 < 5000 : 무조건 1000원 선택
    if X - (N - i - 1) * 1000 < 5000:
        X -= 1000
        answer += arr[i][1]
    else:
        if arr[i][0] > arr[i][1]:
            X -= 5000
            answer += arr[i][0]
        else:
            X -= 1000
            answer += arr[i][1]

# result
print(answer)