# custom comparator 부분 코드 참조

import heapq as hq

# custom comparator (cost value -> min heap)
class Job(object):
    def __init__(self, begin=0, cost=0):
        self.begin = begin
        self.cost = cost

    def __lt__(self, other):
        return self.cost < other.cost

    def __le__(self, other):
        return self.cost <= other.cost


def solution(jobs):
    answer = 0
    pq = []
    hq.heapify(pq)

    # 요청 시간 기준 정렬
    jobs.sort(key=lambda x: x[0])
    TimeCheck = 0
    index = 0

    # exit condition : 모든 jobs가 heapq에 들어가고 heapq가 pop에 의해 empty가 되었을 때
    while len(pq) != 0 or index < len(jobs):
        # (들어갈 jobs가 존재) and (앞선 job의 end time보다 start가 작은 경우) : heapq에 추가
        if (index < len(jobs)) and (TimeCheck >= jobs[index][0]):
            job = Job(begin=jobs[index][0], cost=jobs[index][1])
            hq.heappush(pq, job)
            index += 1
            continue

        # heapq에 값이 있는 경우 늘어난 시간, 총 시간 계산
        if len(pq) != 0:
            job = hq.heappop(pq)
            TimeCheck += job.cost
            answer += TimeCheck - job.begin
        else:
            # heapq에 없는 경우 다음 index 시작점으로 초기화
            TimeCheck = jobs[index][0]

    # 평균값 return
    return int(answer / len(jobs))