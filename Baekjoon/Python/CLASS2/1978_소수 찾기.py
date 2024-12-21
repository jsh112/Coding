def isPrime(H):
    # 0 ~ H, (H + 1)
    arr = [True] * (H + 1)
    arr[0] = arr[1] = False
    for num in range(2, int(H**0.5) + 1):
        if arr[num]:
            arr[num**2:H+1:num] = [False] * len(range(num**2,H+1,num))
    return [i for i in range(2, H+1) if arr[i]]

n = int(input())
n = 1000
my_list = list(map(int, input().split()))

sum = 0
prime = isPrime(n)
for value in my_list:
    if value in prime:
        sum += 1

print(sum)