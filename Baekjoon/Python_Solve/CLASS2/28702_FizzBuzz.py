""" 
1. 3의 배수, 5의 배수이면 FizzBuzz
2. 3의 배수이지만 5의 배수가 아니면 Fizz
3. 3의 배수는 아니지만 5의 배수이면 Buzz
4. 두 개의 배수가 아니면 숫자가 그대로

-> 다음으로 출력될 것은?

숫자 -> .isdigit()
문자열 -> .isalpha()

Fizz -> 3, 6, 9, 12, 18, 21, ...
Buzz -> 5, 10, 20, 25, ...
FizzBuzz -> 15, 30, 45, ... 
"""

my_list = [int(x) if x.isdigit() else x for x in [input() for _ in range(3)]]
    
num = 0
for idx in range(3):
    if type(my_list[idx]) == int:
        num = int(my_list[idx]) + (3 - idx)
        
if num % 3 == 0 and num % 5 == 0:
    print("FizzBuzz")
elif num % 3 == 0:
    print("Fizz")
elif num % 5 == 0:
    print("Buzz")
else:
    print(num)
