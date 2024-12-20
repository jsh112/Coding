n = int(input())

for _ in range(n):
    d, my_str = input().split()
    d = int(d)
    for char in my_str:
        print(d * char, end="")
    print()