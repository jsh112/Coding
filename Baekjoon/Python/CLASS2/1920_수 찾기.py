def binary_search(arr, value):
    low, high = 0, len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        
        if arr[mid] == value:
            return True
        elif arr[mid] > value:
            high = mid - 1
        else:
            low = mid + 1
    return False

# 숫자, 인덱스, 찾았는지 여부
n = int(input())
find = list(map(int, input().split()))

m = int(input())
cand = list(map(int, input().split()))

find.sort()

for item in cand:
    if binary_search(find, item):
        print(1)
    else:
        print(0)