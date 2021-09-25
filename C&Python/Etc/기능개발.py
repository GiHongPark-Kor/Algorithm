def solution(progresses, speeds):
    #변수 초기화
    idx = 0
    answer = []
    day = []
    
    # 배포까지 날짜 계산하기
    for i in range(len(progresses)):
        d = int((100 - progresses[i]) / speeds[i])
        r = int((100 - progresses[i]) % speeds[i])
        day.append(d)
        if r != 0 :
            day[i] += 1
    
    # 배포마다 answer 변수에 count
    answer.append(1)
    temp = day[0]
    for i in range(len(day) - 1):
        if(temp >= day[i + 1]):
            answer[idx] += 1
        else:
            idx += 1
            temp = day[i + 1]
            answer.append(1)    
    
    return answer