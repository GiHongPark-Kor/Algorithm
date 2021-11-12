answer = []
    
def dfs(tickets, check, cur_list, cnt):
    global answer

    #exit condition
    if cnt == len(tickets):
        if len(answer) == 0:
            answer = cur_list[:]
        else:
            for i in range(len(answer)):
                if answer[i] > cur_list[i]:
                    answer = cur_list[:]
                    break
                elif answer[i] == cur_list[i]:
                    continue
                else:
                    break
        return
    
    for i in range(len(tickets)):
        if (check[i] == 0 and len(cur_list) == 0) or (check[i] == 0 and (cur_list[-1] == tickets[i][0])):
            check[i] = 1
            cur_list.append(tickets[i][1])
            dfs(tickets, check, cur_list ,cnt + 1)
            cur_list.pop()
            check[i] = 0
            
    
def solution(tickets):
    check = [0] * len(tickets)
    dfs(tickets, check, ['ICN'], 0)
    return answer