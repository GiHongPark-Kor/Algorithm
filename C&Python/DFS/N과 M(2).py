def solution(N, M, index, cnt, ary):
	#exit condition
	if M == cnt:
		for i in range(len(ary)):
			print(ary[i], end=" ")
		print()
		return

	if index > N:
		return	

	# visit
	ary.append(index)
	solution(N, M, index + 1, cnt + 1, ary)
	ary.pop()

	# not visit
	solution(N, M, index + 1, cnt, ary)		 

N, M = map(int, input().split())
arylist = []
solution(N, M, 1, 0, arylist)