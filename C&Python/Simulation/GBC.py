import sys

# 입력 및 초기화
input1 = list(map(str, input()))
input2 = list(map(str, input()))
d = list([0] * 5 for _ in range(5))
dic = {}
cnt = 0

# 5x5 표로 변환 과정
for i in range(len(input2)):
    if ord(input2[i]) not in dic:
        dic[ord(input2[i])] = [cnt // 5, cnt % 5]
        d[cnt // 5][ cnt % 5] = input2[i]
        cnt += 1
    else:
        continue

for i in range(65, 65 + 26):
    if i == 74:
        continue

    if i not in dic:
        dic[i] = [cnt // 5, cnt % 5]
        d[cnt // 5][ cnt % 5] = chr(i)
        cnt += 1


# 2글자씩 나누는 과정
cnt = 0
i = 0
input1.append('end')
temp = []
while i < len(input1) - 1:
    if input1[i + 1] == 'end':
        temp.append(input1[i])
        temp.append('X')
        break

    if input1[i] == input1[i + 1]:
        if input1[i] != 'X':
            temp.append(input1[i])
            temp.append('X')
        else:
            temp.append(input1[i])
            temp.append('Q')
        i += 1
    else:
        temp.append(input1[i])
        temp.append(input1[i + 1])
        i += 2

# 암호화 과정
i = 0
result = []
while i < len(temp):
    r1 = dic[ord(temp[i])][0]
    c1 = dic[ord(temp[i])][1]
    r2 = dic[ord(temp[i + 1])][0]
    c2 = dic[ord(temp[i + 1])][1]
    if r1 == r2:     
        result.append(d[r1][(c1 + 1) % 5])
        result.append(d[r2][(c2 + 1) % 5])
    elif c1 == c2:    
        result.append(d[(r1 + 1) % 5][c1])
        result.append(d[(r2 + 1) % 5][c2])
    else:          
        result.append(d[r1][c2])
        result.append(d[r2][c1])
    i += 2

print(''.join(result))




