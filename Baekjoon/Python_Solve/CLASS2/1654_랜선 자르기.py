import sys
input = sys.stdin.readline

k, n = map(int, input().split())

cable = []
for _ in range(k):
    cable.append(int(input()))