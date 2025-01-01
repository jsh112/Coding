""" n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

arr.sort(key=lambda x: (x[0], x[1]))

for item in arr:
    print(f'{item[0]} {item[1]}')
"""

n = int(input())
arr = [tuple(map(int, input().split())) for _ in range(n)]

arr.sort()

for item in arr:
    print(*item)
