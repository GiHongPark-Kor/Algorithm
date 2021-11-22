# input : start, end
s = list(map(int, input().split()))
e = list(map(int, input().split()))

# y : years -> days, m : months -> days , ynum : 연도 수
y = (e[0] - s[0]) * 12 * 30
m = (e[1] - s[1]) * 30
d = (e[2] - s[2])
ynum = (e[0] - s[0])

# ans1 : 연차 총 갯수, ans2 : 월차 총 갯수
ans1 = 0
ans2 = 0
for i in range(1,ynum+1):
    if i == ynum:
        if (y + m + d) // 360 == ynum:
            ans1 += (i - 1) // 2 + 15
    else:
        ans1 += (i - 1) // 2 + 15

ans2 = (y + m + d) // 30
if ans2 > 36:
    ans2 = 36

# 결과 값 출력
print(ans1, ans2)
print(str(y + m + d) + "days")