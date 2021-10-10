def solution(array, commands):
    answer = []
    for i in range(len(commands)):
        sub_str = array[(commands[i][0] - 1):commands[i][1]]
        sub_str.sort()
        answer.append((sub_str[commands[i][2] - 1]))
    return answer