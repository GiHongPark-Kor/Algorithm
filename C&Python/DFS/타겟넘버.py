answer = 0
def dfs(numbers, target, cur_total, index):
    global answer
    #exit condition
    if index == len(numbers):
        if cur_total == target:
            answer += 1
        return
    
    # +
    dfs(numbers, target, cur_total + numbers[index], index + 1)
    
    # -
    dfs(numbers, target, cur_total - numbers[index], index + 1)
    
def solution(numbers, target):
    dfs(numbers, target, 0, 0)
    return answer