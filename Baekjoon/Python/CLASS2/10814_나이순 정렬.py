""" def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x[0] < pivot[0] or (x[0] == pivot[0] and x[2] < pivot[2])]
    right = [x for x in arr if x[0] > pivot[0] or (x[0] == pivot[0] and x[2] > pivot[2])]
    return quick_sort(left) + [pivot] + quick_sort(right)
    
n = int(input())

arr = []
for i in range(n):
    age, name = input().split()
    arr.append([int(age), name, i])

sorted_arr = quick_sort(arr)
for item in sorted_arr:
    print(f'{item[0]} {item[1]}') """
    
n = int(input())
arr = [(*input().split(), i) for i in range(n)] 

arr.sort(key=lambda x: (int(x[0]), x[2]))

for item in arr:
    print(item[0], item[1])
