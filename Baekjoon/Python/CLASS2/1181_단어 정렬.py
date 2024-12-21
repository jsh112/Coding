def quick_sort(arr):
    # 탈출 조건
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if len(x) < len(pivot) or (len(x) == len(pivot) and x < pivot)]
    right = [x for x in arr if len(x) > len(pivot) or (len(x) == len(pivot) and x > pivot)]
    return quick_sort(left) + [pivot] + quick_sort(right) 

n = int(input())  
arr = [input().strip() for _ in range(n)]  

sorted_arr = quick_sort(arr)  
for item in sorted_arr:
    print(item)
