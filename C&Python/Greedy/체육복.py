check = [1 for i in range(32)]


def solution(n, lost, reserve):
    answer = 0
    reserve.sort()
    lost.sort()
    for i in range(len(lost)):
        check[lost[i]] -= 1
        
    for i in range(len(reserve)):
        check[reserve[i]] += 1

    for i in range(len(lost)):
            
        if lost[i] == 1:
            if check[2] >= 2 and check[lost[i]] == 0:
                check[2] -= 1
                check[lost[i]] += 1    
                
        elif 1 < lost[i] < n:
            if check[lost[i] - 1] >= 2 and check[lost[i]] == 0:
                check[lost[i] - 1] -= 1
                check[lost[i]] += 1
            elif check[lost[i] + 1] >= 2 and check[lost[i]] == 0:
                check[lost[i] + 1] -= 1
                check[lost[i]] += 1
        elif lost[i] == n:
            if check[n - 1] >= 2 and check[lost[i]] == 0:
                check[n - 1] -= 1
                check[lost[i]] += 1

                
    for i in range(1,n+1,1):
        if check[i] > 0:
            answer += 1

    return answer