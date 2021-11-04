answer = int(1e10)
def dfs(cur_str, target, words,check, cnt):
    global answer
    if answer != int(1e10) and answer < cnt:
        return
    # exit condition if 가능 -> answer값 변경
    if cur_str == target:
        if answer > cnt:
            answer = cnt
        return
    
    # for문 이용(전체 탐색, cur_srt의 부분 중 2개 일치하여 바꿀 수 있는 단어 있으면 dfs 실행 + check)
    for j in range(len(words)):
        cnt2 = 0
        temp = words[j]
        if check[j] == 0:
            for i in range(len(cur_str)):
                if words[j].find(cur_str[i]) != -1:
                    words[j] = words[j].replace(cur_str[i],'',1)
                    cnt2 += 1
            if cnt2 == len(cur_str) - 1:
                check[j] = 1
                words[j] = temp
                dfs(words[j], target, words, check, cnt + 1)
                check[j] = 0
        words[j] = temp

def solution(begin, target, words):
    global answer
    check = [0] * len(words)
    if target not in words:
        return 0
    dfs(begin,target,words,check,0)
    if (answer == int(1e10)):
        answer = 0
    return answer