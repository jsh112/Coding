arr = []

while True:
    tmp = input()
    if tmp == "0":
        break
    else:
        arr.append(tmp)
        
for value in arr:
    # reverse
    if value == value[::-1]:
        print("yes")
    else:
        print("no")