""" 
수는 중복되지 않기 때문에 그냥 quick sort를 잘 섞으면 될듯하다.

->
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

여기서 중요한 것은 입력되는 수의 절댓값이 개수의 크기를 절대 넘을 수 없다......
그냥 카운팅을 하자

음수가 포함되어있다.
-십만 ~ -1 -> 0 ~ 10만 - 1
"""

import sys
input = sys.stdin.readline


n = int(input())
const = 1000000
arr = [0] * (2 * const + 1)

for _ in range(n):
    num = int(input())
    arr[num + const] = 1
    
for i in range(len(arr)):
    if arr[i]:
        print(i - const)