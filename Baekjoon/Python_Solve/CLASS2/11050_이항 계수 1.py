""" 
nCk -> n! / k! * (n - k)!

n * (n-1) * ... * (n - k + 1) / 1 * 2 * 3 * ... * k
"""
n, k = map(int, input().split())

comb = 1
for i in range(1, k+1):
    comb = comb * (n - k + i) // i
print(comb)