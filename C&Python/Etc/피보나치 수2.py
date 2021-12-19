# 피보나치 수열을 계산하는 순환 알고리즘의 시간 복잡도는 O(2^n)
# 피보나치 수열을 계산하는 반복 알고리즘의 시간 복잡도는 O(n)

if __name__ == "__main__":
    N = int(input())
    d = [0] * 91
    d[1] = 1
    for i in range(2, 91):
        d[i] = d[i - 1] + d[i - 2]

    print(d[N])