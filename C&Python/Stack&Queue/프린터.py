from queue import Queue


def solution(priorities, location):
    # 초기화
    answer = 1
    k = 0
    que = Queue()
    sort_list = []
    find_value = priorities[location]
    find_location = location
    
    # queue, 정렬 list insert(튜플 형태)
    for i in range(len(priorities)):
        que.put((priorities[i], i))
        sort_list.append(priorities[i])
    
    # 정렬 list sort
    sort_list.sort(reverse=True)
    
    while que.empty() == False:     
        # queue의 front 값 pop
        max_value = sort_list[k]
        get_value, get_index = que.get()
        
        # 우선순위 가장 큰가? and 요청한 값인가? => true면 return
        if get_value == max_value:
            if get_value == find_value and get_index == find_location:
                return answer
            answer += 1
            k += 1
        else:
            # 다시 queue에 push
            que.put((get_value, get_index))
    
    # 찾는 값이 없는 경우.
    return -1 