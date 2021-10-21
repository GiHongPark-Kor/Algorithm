T = int(input().strip())
for tnum in range(T):
	answer = 0
	#input
	N = int(input().strip())
	input_list = [list(map(int,input().split())) for _ in range(N)]
	
	#print(input_list)
	# x 위치, y 위치, 이동 방향, 보유 에너지 K
	# 상(0), 하(1), 좌(2), 우(3)
	for i in range(len(input_list)):
		input_list[i][0] += 1000
		input_list[i][1] += 1000
	#print(input_list)
	total = 4000
	#print(input_list)
	#print(len(input_list))
	while total > 0:
		#print(input_list)
		dic = {}
		remove_list = []
		for i in range(len(input_list)):
			if len(input_list[i]) == 0: continue
			if input_list[i][2] == 0:
				if input_list[i][1] + 0.5 <= 200000:
					input_list[i][1] += 0.5
				else:
					input_list[i].clear()
					continue
			elif input_list[i][2] == 1:
				if input_list[i][1] - 0.5 >= 0: 
					input_list[i][1] -= 0.5
				else:
					input_list[i].clear()
					continue
			elif input_list[i][2] == 2:
				if input_list[i][0] - 0.5 >= 0: 
					input_list[i][0] -= 0.5
				else:
					input_list[i].clear()
					continue
			elif input_list[i][2] == 3:
				if input_list[i][0] + 0.5 <= 200000: 
					input_list[i][0] += 0.5
				else:
					input_list[i].clear()
					continue
	
			if (input_list[i][0],input_list[i][1]) not in dic:
				dic[(input_list[i][0],input_list[i][1])] = (input_list[i][3],i)
			else:
				#answer += dic[(input_list[i][0],input_list[i][1])][0]
				answer += input_list[i][3]
				rpos = dic[(input_list[i][0],input_list[i][1])][1]
				input_list[i].clear()
				if rpos not in remove_list:
					remove_list.append(rpos)
	
		for i in range(len(remove_list)):
			answer += input_list[remove_list[i]][3]
			input_list[remove_list[i]].clear()
	
		total -= 1
	
	print("#" + str(tnum + 1) +" " +str(answer))