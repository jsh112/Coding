""" 
1. 3으로 나누기
2. 2로 나누기
3. 1을 빼기

어떤 자연수 N이 있다고 하자.
3의 배수 -> 모든 자리수의 합이 3의 배수
2의 배수 -> 끝자리가 0, 2, 4, 6, 8

1. 1을 뺐을 때 3의 제곱수라면 3으로 나눠야 한다.
1을 뺐을 때 2의 제곱수라면 2로 나눠야한다.


10 -> 5 또는 9 -> 9를 선택
그럼, 제곱수들에 미리 값을 채워넣을까?

메모리 제한 128MB

리스트 하나 -> 64byte
리스트 각 요소당 int + pointer 36byte

64 + 10^6 * 36 => 36 * 10^6

1MB = 2^20 Byte

2^2 * 9 * 2^6 * 5^6 // 2^20

9 * 5^6 // 2^12 = 34MB 충분함

"""

""" 
N = int(input())
my_inf = 1000000
num_list = [1] * (my_inf + 1)
num_list[0] = num_list[1] = 0

for num in range(4, len(num_list)):
    num_1, num_2, num_3 = my_inf, my_inf, my_inf
    if num % 2 == 0:
        num_2 = num // 2
        num_2 = num_list[num_2]
    elif num % 3 == 0:
        num_3 = num // 3
        num_3 = num_list[num_3]
    num_1 = num - 1
    num_1 = num_list[num_1]
    
    mmin = min(num_1, num_2, num_3)
    
    num_list[num] = mmin + 1
    
print(num_list[N])

"""
N = int(input())
num_list = [0] * (N + 1)

for i in range(2, N + 1):
    num_list[i] = num_list[i - 1] + 1
    
    if i % 2 == 0:
        num_list[i] = min(num_list[i], num_list[i // 2] + 1)
    if i % 3 == 0:
        num_list[i] = min(num_list[i], num_list[i // 3] + 1)
    
print(num_list[N])