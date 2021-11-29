import sys

def solution(people, limit):
    answer = 0
    check = [0] * len(people)
    people.sort()
    lpos = 0
    rpos = len(people) - 1
    while(lpos <= rpos):
        l = lpos
        r = rpos
        if people[l] + people[r] <= limit:
            answer += 1
            lpos += 1
            rpos -= 1
        else:
            answer += 1
            rpos -= 1
        

    return answer