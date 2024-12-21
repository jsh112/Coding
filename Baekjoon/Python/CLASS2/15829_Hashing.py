n = int(input())
string = input()

h = 0
r = 31
M = 1234567891
for i in range(n):
    h += (((r ** i) % M) * (ord(string[i]) - ord('a') + 1)) % M
    h %= M
print(h)