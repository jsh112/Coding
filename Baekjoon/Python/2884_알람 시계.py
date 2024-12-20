time, minute = map(int, input().split())

if minute < 45:
    minute += 15
    time = (time + 23) % 24
else:
    minute -= 45
    
print(f'{time} {minute}')