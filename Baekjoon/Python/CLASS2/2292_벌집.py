num = int(input())

""" 
1층 : 1 -> 1개
2층 : 2 ~ 7 -> 6개
3층 : 8 ~ 19 -> 12개
4층 : 20 ~ 37 -> 18개
5층 : 38 ~ 61 -> 24개
a_n = 6*(n - 1) + 1(n != 1)
"""

floor = 1
house = 1
idx = 1

while num > house:
    house += idx * 6
    idx += 1
    floor += 1

print(floor)