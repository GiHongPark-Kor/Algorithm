def solution(genres, plays):
    answer = []
    
    dic_count = [0] * 101
    dic_list = {}
    genres_count = [[0,0]] * 101
    cnt = 0
    for i in range(len(genres)):
        if genres[i] not in dic_count:
            dic_count[cnt] = genres[i]
            print(genres[i], dic_list)
            dic_list[genres[i]] = []
            dic_list[genres[i]].append([plays[i],i])
            genres_count[cnt] = [plays[i], cnt]
            cnt += 1
        else:
            dic_list[genres[i]].append([plays[i],i])
            genres_count[dic_count.index(genres[i])][0] += plays[i]
            
    genres_count = sorted(genres_count, key = lambda x : x[0], reverse = True)

    for i in range(len(genres)):
        if genres_count[i][0] == 0:
            break
        else:	
            cur_list= dic_list[dic_count[genres_count[i][1]]]
            cur_list = sorted(cur_list, key = lambda x : x[0], reverse = True)
            if len(cur_list) == 1:
                answer.append(cur_list[0][1])
            else:
                for j in range(2):
                    answer.append(cur_list[j][1])
            
            
    return answer