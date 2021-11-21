N, H, W = map(int, input().split())
data = list(list(map(str, input())) for _ in range(H))
r_data = ['?'] * (N)
for i in range(len(data)):
	for j in range(len(data[i])):
		if data[i][j] != '?':
			r_data[j // W] = data[i][j] # 가로 값 복원

print(''.join(r_data))