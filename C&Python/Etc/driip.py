arr = list(map(str,input()))
size = len(arr)
if size >= 5:
    if ''.join(arr[size - 5:]) == "driip":
        print("cute")
    else:
        print("not cute")
else:
    print("not cute")