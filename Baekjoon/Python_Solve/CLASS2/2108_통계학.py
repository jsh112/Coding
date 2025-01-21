""" 
0 -> -3999
...
3999 -> 0
...
7998 -> 3999
"""
import sys
input = sys.stdin.readline
n = int(input())

arr = []
idx = n // 2
sum = 0
for _ in range(n):
    tmp = int(input())
    sum += tmp
    arr.append(tmp)

# 평균    
avg = round(sum / n)
arr.sort()

cnt, max_cnt = 1, 0
mode = 1
tmp_arr = []
for i in range(len(arr) - 1):
    if arr[i] != arr[i + 1]:
        if max_cnt < cnt:
            max_cnt = cnt
        tmp_arr.append([arr[i], cnt])
        cnt = 1
    else:
        cnt += 1
tmp_arr.append([arr[-1], cnt])
tmp_arr.sort(key=lambda x: (x[1], x[0]))

if n == 1:
    mode = arr[0]

elif tmp_arr[-1][1] > tmp_arr[-2][1]:
    mode = tmp_arr[-1][0]

else:
    for i in range(len(tmp_arr) - 1, 0,-1):
        if tmp_arr[i][1] != tmp_arr[i - 1][1]:
            mode = tmp_arr[i + 1][0]


print(avg)
print(arr[idx])
print(mode)
print(arr[-1] - arr[0])
