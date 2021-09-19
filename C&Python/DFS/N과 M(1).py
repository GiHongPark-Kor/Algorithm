check = [0 for i in range(9)]
v = [0 for i in range(9)]

def solution(n,m,index):
    if m == index:
        for i in range(m):
            print(v[i], end=' ')
        print(end='\n')
        return;

    for i in range(1,n + 1,1):
        if check[i] != 1:
            check[i] = 1
            v[index] = i
            solution(n,m,index +1)
            check[i] = 0


n, m = map(int, input().split())


solution(n,m,0)
