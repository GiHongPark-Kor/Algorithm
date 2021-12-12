N = int(input())
line = []
arr = list(map(int,input().split()))

for i in range(len(arr)):
    if arr[i] == 0:
        line.append(i + 1)
    else:
        line.insert(-arr[i],i + 1)

for i in line:
    print(i,end=" ")