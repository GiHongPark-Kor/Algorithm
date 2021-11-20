# 입력 및 초기화
x = int(input())
arr = list(map(int, input().split()))
d = [1] * x

# solution
for i in range(x):
    for j in range(i):
        if arr[i] > arr[j]:
            d[i] = max(d[i], d[j]+1)

# 결과 값 출력
print(max(d))