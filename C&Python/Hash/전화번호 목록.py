def solution(phone_book):
    phone_book.sort(key=len);
    dic = {}
    for i in range(len(phone_book)):
        dic[phone_book[i]] = 1
        
    for i in range(len(phone_book)):
        str = ""
        for j in range(len(phone_book[i])):
            str += phone_book[i][j]
            if str in dic and str != phone_book[i]:
                return False
    return True