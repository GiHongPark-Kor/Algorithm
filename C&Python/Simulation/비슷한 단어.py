N = int(input())
first_word = list(map(str, input()))
first_alpha = [0]*27
for i in first_word:
    first_alpha[ord(i)-ord('A')] +=1

answer = 0
for i in range(1,N):
    word = list(map(str,input()))
    word_alpha = [0] * 27
    diff = 0
    check = False

    if abs(len(word) - len(first_word)) >= 2:
        continue

    for j in word:
        word_alpha[ord(j) - ord('A')] += 1

    for k in range(27):
        if abs(word_alpha[k] - first_alpha[k]) >= 2:
            check = True
            break
        diff += abs(word_alpha[k] - first_alpha[k])

    if check == True:
        continue

    if diff <= 2 :
        answer += 1

print(answer)

# 사용테스트케이스
"""
10
DDOG
GOD
GOOD
DOLL
DOOOLL
DO
DOC
COG
DOGG
DDOG
"""