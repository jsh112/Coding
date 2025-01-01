import sys
input = sys.stdin.readline

n = int(input())
count_idx = [0] * 10001

for _ in range(n):
    count_idx[int(input()) - 1] += 1
    
for i in range(len(count_idx)):
    if count_idx[i] != 0:
        for _ in range(count_idx[i]):
            print(f'{i + 1}')