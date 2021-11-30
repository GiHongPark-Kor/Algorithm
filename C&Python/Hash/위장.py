def solution(clothes):
    answer = 1
    cnt = {}
    for i in range(len(clothes)):
        if clothes[i][1] not in cnt:
            cnt[clothes[i][1]] = 2
        else:
            cnt[clothes[i][1]] += 1
    #print(cnt)
    
    cnt_list = list(cnt.values())
    for i in cnt_list:
        answer *= i
        
    #print(cnt_list)
    
    return answer - 1