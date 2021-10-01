import heapq as hq

# custom comparator : max heap
class Operation1(object):
    def __init__(self, cost=0):
        self.cost = cost

    def __gt__(self, other):
        return int(self.cost) < int(other.cost)

# custom comparator : min heap
class Operation2(object):
    def __init__(self, cost=0):
        self.cost = cost

    def __lt__(self, other):
        return int(self.cost) < int(other.cost)

def solution(operations):
    # 초기화
    maxqueue = []
    minqueue = []
    hq.heapify(maxqueue)
    hq.heapify(minqueue)
    answer = []
    insert_num = 0
    
    # 연산수행
    for i in range(len(operations)):
        c = operations[i][0]
        if c == 'I':
            # max, min heap에 2번 push
            v1 = Operation1(cost=operations[i][2:])
            v2 = Operation2(cost=operations[i][2:])
            hq.heappush(maxqueue, v1)
            hq.heappush(minqueue, v2)
            insert_num += 1
        elif c == 'D':
            # (pop 전) 현재 큐가 비어있다면
            if (len(maxqueue) + len(minqueue)) == insert_num:
                continue
                
            # pop 과정 : max or min heap에서 빼주기    
            v = int(operations[i][2:])
            if v == 1:
                hq.heappop(maxqueue)
            else:
                hq.heappop(minqueue)  
            
            # (pop 후) 큐가 비어있다면
            if (len(maxqueue) + len(minqueue)) == insert_num:
                maxqueue.clear()
                minqueue.clear()
                insert_num = 0
   
    # return 값 처리
    if (len(maxqueue) + len(minqueue)) == insert_num:
        # (처리 후) 빈 큐
        return [0, 0]
    else:
        if (len(maxqueue) + len(minqueue)) - insert_num == 1:
            # (하나의 값이 남았을 경우) max or min heap에서 pop
            v = hq.heappop(maxqueue)
            answer.append(int(v.cost))
            answer.append(int(v.cost))
        else:
            # (두개 이상 값이 남았을 경우) max and min heap에서 pop
            v1 = hq.heappop(maxqueue)
            v2 = hq.heappop(minqueue)
            answer.append(int(v1.cost))
            answer.append(int(v2.cost))
            
    return answer