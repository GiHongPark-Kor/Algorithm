import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    arr = []

    for i in range(N):
        temp = list(map(str, sys.stdin.readline().split()))
        temp.append(i)
        arr.append(temp)
    arr = sorted(arr, key = lambda x : (int(x[0]),x[2])) # 문자일 때 정렬하면 실패!

    for i in range(N):
        print(arr[i][0], arr[i][1])
