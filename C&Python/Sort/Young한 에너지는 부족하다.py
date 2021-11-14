N = int(input())
arr = list(map(int, input().split()))
arr = sorted(arr)
temp = []
for i in range(N):
	temp.append([])

for i in range(3 * N):
	temp[i % N].append(arr[i])

arr = sorted(temp, key = lambda x : x[1], reverse = True)
print(abs(arr[0][1] - arr[-1][1]))