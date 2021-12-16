def rome_to_arabic(strlist):
    l = len(strlist)
    i = 0
    v = []
    while i < l:
        if i + 1 < l:
            if ''.join(strlist[i:i+2]) in exception_dic:
                v.append(exception_dic[''.join(strlist[i:i+2]) ])
                i += 2
                continue
        v.append(dic[strlist[i]])
        i += 1
    return sum(v)

def arabic_to_rome(num):
    answer = []
    before = ""
    check = {}
    while True:
        if num >= 1000 and answer[-3:] != 'MMM':
            num -= 1000
            answer.append('M')
            before = 'M'
        elif num >= 900 and before != 'CD':
            num -= 900
            answer.append('CM')
            before = 'CM'
        elif num >= 500 and 'D' not in check:
            num -= 500
            answer.append('D')
            before = 'D'
            check['D'] = 1
        elif num >= 400 and before != 'CM':
            num -= 400
            answer.append('CD')
            before = 'CD'
        elif num >= 100 and answer[-3:] != 'CCC':
            num -= 100
            answer.append('C')
            before = 'C'
        elif num >= 90 and before != 'XL':
            num -= 90
            answer.append('XC')
            before = 'XC'
        elif num >= 50 and 'L' not in check:
            num -= 50
            answer.append('L')
            before = 'L'
            check['L'] = 1
        elif num >= 40 and before != 'XC':
            num -= 40
            answer.append('XL')
            before = 'XL'
        elif num >= 10 and answer[-3:] != 'XXX':
            num -= 10
            answer.append('X')
            before = 'X'
        elif num >= 9 and before != 'IV':
            num -= 9
            answer.append('IX')
            before = 'IX'
        elif num >= 5 and 'V' not in check:
            num -= 5
            answer.append('V')
            before = 'V'
            check['V'] = 1
        elif num >= 4 and before != 'IX':
            num -= 4
            answer.append('IV')
            before = 'IV'
        elif num >= 1 and answer[-3:] != 'III':
            num -= 1
            answer.append('I')
            before = 'I'
        else:
            return answer

exception_dic = {'IV' : 4, 'IX' : 9, 'XL' : 40, 'XC' : 90, 'CD' : 400, 'CM' : 900}
dic = {'I':1,	'V':5,	'X':10,	'L':50,	'C':100, 'D':500, 'M' :1000}
str1 = list(map(str,input()))
str2 = list(map(str,input()))
num1 = rome_to_arabic(str1)
num2 = rome_to_arabic(str2)

# 결과 출력
print(num1 + num2)
print(''.join(arabic_to_rome(num1 + num2)))
