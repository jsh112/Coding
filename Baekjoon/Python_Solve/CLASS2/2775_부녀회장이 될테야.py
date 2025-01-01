
""" 
a층 b호에 살려면 자신의 아래 (a-1)층의 1 ~ b호까지의 사람들의 수의 합만큼 사람을 데려와야함
아파트는 0층부터 있음 
k층 n호에 입주할 예정
0층의 i호에는 i명이 삼, i는 1부터 시작
0층 : 1호, 2호, ...
"""
test_case = int(input())

# 0층은 최대 14
apart = [[i for i in range(1, 15)]]
# print(len(apart))

for _ in range(test_case):
    k = int(input())
    n = int(input())
    
    while len(apart) <= k:
        new_floor = [sum(apart[-1][:room + 1]) for room in range(14)]
        apart.append(new_floor)
    
    print(apart[k][n - 1])