import sys

if __name__ == "__main__":
    input_data = list(map(int, sys.stdin.readline().split()))
    a_check = True # ascending check
    d_check = True # descending check
    m_check = True # mixed check

    for i in range(7):
        if input_data[i] + 1 == input_data[i + 1]:
            pass
        else:
            a_check = False
            break

    if a_check == True:
        print("ascending")
        m_check = False

    for i in range(7):
        if input_data[i] - 1 == input_data[i + 1]:
            pass
        else:
            d_check = False
            break

    if d_check == True:
        print("descending")
        m_check = False

    if m_check == True:
        print("mixed")