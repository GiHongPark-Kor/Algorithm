if __name__ == "__main__":
    # input
    N = int(input())
    arr = []
    for i in range(N):
        s, e = map(int, input().split())
        arr.append([s,e])

    arr = sorted(arr, key = lambda x : x[1])
    temp = -1
    answer = 0
    
    for i in range(len(arr)):
        if temp > arr[i][0]:
            pass
        else:
            temp = arr[i][1]
            answer += 1
    print(answer)

