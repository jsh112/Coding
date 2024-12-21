num = int(input())
# 길이 -> 자리수, 9 * 자리수만큼만 진행
num_str = str(num)
num_print = 0

""" 
10 -> 2자리이므로 이론상 9 * 2까지 뺄 수 있음
하지만 10 < 18이므로 tmp >= 0 조건을 둬야 함.
"""

for i in range(len(num_str) * 9 + 1):
    tmp = num - i
    if tmp >= 0 and sum(map(int, str(tmp))) + tmp == num:
        num_print = tmp

print(num_print)