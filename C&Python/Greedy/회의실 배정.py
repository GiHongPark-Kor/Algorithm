if __name__ == "__main__":
    # input
    N = int(input())
    arr = []
    for _ in range(N):
        s, e = map(int, input().split())
        arr.append([s,e])

    # 예외 테스트 케이스 : (1, 2) (2, 2) -> s 정렬도 필요!!
    arr = sorted(arr, key = lambda x : (x[1],x[0]))
    temp = -1
    answer = 0

    for i in range(len(arr)):
        if temp > arr[i][0]:
            pass
        else:
            temp = arr[i][1]
            answer += 1
    print(answer)

