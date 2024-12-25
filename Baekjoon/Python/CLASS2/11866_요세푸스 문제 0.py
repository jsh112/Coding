import sys
input = sys.stdin.readline

def solution(n, k):
    arr = list(range(1, n + 1))
    idx = 0
    result = []
    
    while arr:
        idx = (idx + k - 1) % len(arr)
        result.append(arr.pop(idx))
        
    print("<" + ", ".join(map(str, result)) + ">")

n, k = map(int, input().split())

solution(n, k)