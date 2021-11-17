N, L = map(int, input().split())
arr = list(map(int, input().split()))
sumV = sum(arr) - arr[0]
#avg = sumV / (N - 1)
check = False
for i in range(1,N):
    x1 = arr[i - 1] - L
    x2 = arr[i - 1] + L
    avg = sumV / (N - i)
    if x1 < avg < x2:
        sumV -= arr[i]
        continue
    else:
        print("unstable")
        check = True
        break

if check != True:
    print("stable")