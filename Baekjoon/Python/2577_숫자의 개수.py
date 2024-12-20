mul = 1
for _ in range(3):
    mul *= int(input())
    
mul = str(mul)
ex_dict = dict()
for i in range(10):
    ex_dict[f'{i}'] = 0
for char in mul:
    ex_dict[char] += 1

for key,value in ex_dict.items():
    print(value)