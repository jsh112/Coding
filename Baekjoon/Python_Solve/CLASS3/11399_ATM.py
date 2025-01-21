""" 
CPU Scheduling이랑 비슷한 느낌을 받는다.
person[0]는 본인의 시간 1
person[1] 은 time[0] + 2
즉, 앞사람의 시간이 짧아질수록 각 사람이 기다리는 합은 작아질듯

7
1 2 3 4 5 6 7

1. 1분
2. 1분 + (1 + 1)분 = 3분
3. 3분 + (2 + 1)분 = 6분
4. 6분 + (3 + 1)분 = 10분
5. 10분 + ()
"""

n = int(input())

time = list(map(int, input().split()))
time.sort()

sum = 0
total = 0
for t in time:
    sum += t
    total += sum

print(total)