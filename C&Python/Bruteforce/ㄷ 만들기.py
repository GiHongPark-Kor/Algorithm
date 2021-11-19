def solution(arr, k, row, col):
    cost = 0
    check = list([0] * m for _ in range(n))

    # 좌표 [row, col]에서 k * k ㄷ이 [n,m] 범위를 넘어가는 경우
    if row + 3 * k - 1 >= n or col + 3 * k - 1 >= m:
        return int(10e9)

    # 좌표 [row, col]에서 k * k ㄷ 만들기
    for i in range(row, row + 3*k):
        for j in range(col, col + 3 *k):
            check[i][j] = 1
            if row + k <= i < row + 2 * k and col + k <= j:
                if arr[i][j] == '#':
                    cost += b
            elif arr[i][j] == '.':
                cost += a



    # 좌표 [row, col]에서 k * k ㄷ 일 때, ㄷ 제외하고 전부 흰색 처리
    for i in range(n):
        for j in range(m):
            if arr[i][j] == '#' and check[i][j] == 0:
                cost += b
    return cost



# 초기화
n, m = map(int, input().split())
a, b = map(int, input().split())
arr = []
for i in range(n):
    temp = list(map(str, input()))
    arr.append(temp)
answer = int(10e9)

# 브루트포스 : k : 1 ~ 6 일 때 모든 좌표에 대해 ㄷ 만들어보기
for k in range(1, 7):
    for i in range(n):
        for j in range(m):
            cost = solution(arr,k,i,j)
            if answer > cost:
                answer = cost

# 결과 출력
print(answer)