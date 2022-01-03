import sys

if __name__ == "__main__":
    arr = list(map(str, sys.stdin.readline()))
    answer = 0

    if '-' not in arr:
        temp = ""
        for i in range(len(arr)):
            if arr[i] == "+":
                answer += int(temp)
                temp = ""
            else:
                temp += arr[i]
        answer += int(temp)
    else:
        n = []
        temp = ""
        for i in range(len(arr)):
            if arr[i] == "+":
                n.append(int(temp))
                temp = ""
            elif arr[i] == "-":
                n.append(int(temp))
                temp = "-"
            else:
                temp += arr[i]
        n.append(int(temp))
        i = 0

        # 그리디 알고리즘 : 음수일 경우 뒤에 양수값 개수만큼 괄호에 포함
        while i < len(n):
            if n[i] < 0:
                j = i + 1
                cv = -n[i]
                while(j < len(n)):
                    if 0 < n[j]:
                        cv = cv + n[j]
                        j += 1
                    else:
                        break
                answer += (-cv)
                i = j
            else:
                answer += n[i]
                i += 1

    print(answer)