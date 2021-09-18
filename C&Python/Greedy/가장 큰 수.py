def solution(number, k):
    answer = "";
    size = len(number) - k;
    index = -1;
    for i in range(size):
        temp = '/';
        for j in range(index+1,k+i+1,1):
            if number[j] > temp:
                temp = number[j]
                index = j

        answer += temp;
    return answer


number = "1928"
k = 2
stack = [number[0]]
for num in number[1:]:
    print(num)
    print(type(num))
    while len(stack) > 0 and stack[-1] < num and k > 0:
        k -= 1
        stack.pop()
    stack.append(num)
if k != 0:
    stack = stack[:-k]
print(''.join(stack))
