""" 
24 18의 최대공약수
a = bq1 + r
b = rq2 + R
(a, b) = (b, r) = (r, R)
(24, 18) = (18, 6) = (6, 0)

24 18의 최소공배수
24 = 6 * 4
18 = 6 * 3

24 * 3 = 18 * 4
24 * 18 / 6 = 24 * 3 = 18 * 4
"""

def gcd(a, b):
    while b:
        a, b = b, a % b

    return a

def lcm(a, b):
    return a * b // gcd(a, b)

m, n = map(int, input().split())
print(f'{gcd(m, n)}\n{lcm(m, n)}')

