import queue

def solution(n, edge):
    # 인접리스트 활용
    answer = 0
    cur_max = 0
    check = [0 for i in range(n + 1)]
    arr = [[0 for i in range(0)] for j in range(n + 1)]
    
    # 양방향 노드의 간선 추가
    for i in range(len(edge)):
        arr[edge[i][0]].append(edge[i][1])
        arr[edge[i][1]].append(edge[i][0])
        
    # 큐 초기화
    q= queue.Queue()
    q.put((1,0))
    check[1] = 1
    
    # bfs -> 마지막 노드 count
    while q.qsize() != 0:
        v, c = q.get()
        if cur_max < c:
            cur_max = c
            answer = 1
        else:
            answer += 1
            
        for i in range(len(arr[v])):
            if check[arr[v][i]] == 0:
                q.put((arr[v][i], c+1))
                check[arr[v][i]] = 1
                
    return answer