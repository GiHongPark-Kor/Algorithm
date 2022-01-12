import sys
 
if __name__ == "__main__":
    # 1. 입력 및 초기화
    W, N = map(int, sys.stdin.readline().split())
    input_info = []
    for i in range(N):
        arr = list(map(int, sys.stdin.readline().split()))
        input_info.append(arr)

    # 2. 무게당 가격순으로 내림차순 정렬
    input_info = sorted(input_info, key=lambda x: -x[1])

    # 3. 순서대로 배낭이 찰 때까지 담는다.
    answer = 0
    idx = 0
    while idx < len(input_info):
        if input_info[idx][0] < W:
            W -= input_info[idx][0]
            answer += input_info[idx][0] * input_info[idx][1]
            idx += 1
        else:
            answer += W * input_info[idx][1]
            break

    # 4. 결과를 출력한다.
    print(answer)
