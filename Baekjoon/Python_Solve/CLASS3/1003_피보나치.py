import sys
input = sys.stdin.readline
t = int(input())

# 0 ~ 40
answer = [[0, 0] for _ in range(41)]

answer[0] = [1, 0]
answer[1] = [0, 1]

for i in range(2, 41):
    answer[i][0] = answer[i - 1][0] + answer[i - 2][0]
    answer[i][1] = answer[i - 1][1] + answer[i - 2][1]

for _ in range(t):
    N = int(input())
    print(*answer[N])