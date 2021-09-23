def solution(participant, completion):
    #sort
    completion.sort()
    participant.sort()
    
    #completion size = participant size - 1
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
    
    #마지막 원소일 경우
    return participant[len(participant)-1]