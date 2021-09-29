# 다른 코드 참조
# Priority Queue : 완벽한 정렬, heapq기반, thread safe한 대신 속도 느리다.
# heapq : 느슨한 정렬, 기본 list를 힙처럼 다룰 수 있게 해준다.
# 이 문제는 Priority Queue 사용하면 시간초과

import heapq as hq

def solution(scoville, K):

    hq.heapify(scoville)
    answer = 0
    while True:
        e1 = hq.heappop(scoville)
        if first >= K:
            break
        if len(scoville) == 0:
            return -1
        e2 = hq.heappop(scoville)
        hq.heappush(scoville, e1 + e2 * 2)
        answer += 1
    return answer
