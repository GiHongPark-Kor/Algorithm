import sys

if __name__ == "__main__":

    arr = list(map(str,input()))
    check = False
    temp = []
    for i in range(len(arr)):
        if arr[i] == '<':
            if len(temp) != 0:
                temp.reverse()
                print(''.join(temp), end="")
                temp = []
            check = True
            print(arr[i], end="")
        elif arr[i] == '>':
            check = False
            print(arr[i], end="")
        elif check == True:
            print(arr[i], end="")
        elif arr[i] == ' ':
            temp.reverse()
            print(''.join(temp), end=" ")
            temp = []
        else:
            temp.append(arr[i])

    if len(temp) != 0:
        temp.reverse()
        print(''.join(temp))