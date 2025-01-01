m, n = map(int, input().split())

arr = [True] * (n + 1)
arr[0] = arr[1] = False

for num in range(2, int(n**0.5) + 1):
    if arr[num]:
        for multiple in range(num * num, n + 1, num):
            arr[multiple] = False

for i in range(m,n+1):
    if arr[i]:
        print(i)