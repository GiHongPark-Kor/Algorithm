import sys
num = []
num.append([1,1,1,0,1,1,1]) #0
num.append([0,0,1,0,0,1,0]) #1
num.append([1,0,1,1,1,0,1]) #2
num.append([1,0,1,1,0,1,1]) #3
num.append([0,1,1,1,0,1,0]) #4
num.append([1,1,0,1,0,1,1]) #5
num.append([1,1,0,1,1,1,1]) #6
num.append([1,1,1,0,0,1,0]) #7
num.append([1,1,1,1,1,1,1]) #8
num.append([1,1,1,1,0,1,1]) #9
num.append([0,0,0,0,0,0,0]) #N

if __name__ == "__main__":
    # input & init
    T = int(sys.stdin.readline())
    board = []
    for _ in range(5):
        board.append([])

    for _ in range(T):
        A, B = map(str,sys.stdin.readline().split())
        answer = 0
        cnt = max(len(A), len(B))

        # 두 입력 값 자릿수 맞추기
        if len(A) < len(B):
            for j in range(len(B) - len(A)):
                A = 'N' + A
        else:
            for j in range(len(A) - len(B)):
                B = 'N' + B

        # 값 계산
        while cnt:
            if A[cnt - 1] == 'N':
                n1 = 10
            else:
                n1 = int(A[cnt - 1])

            if B[cnt - 1] == 'N':
                n2 = 10
            else:
                n2 = int(B[cnt - 1])

            for i in range(7):
                if num[n1][i] == num[n2][i]:
                    pass
                else:
                    if num[n1][i] == 0 and num[n2][i] == 1:
                        answer += 1
                    elif num[n1][i] == 1 and num[n2][i] == 0:
                        answer += 1
            cnt -= 1
        print(answer)