""" n = int(input())

sz = 100000000
arr = [0] * (2 * sz + 1)

arr_input = list(map(int, input().split()))
for num in arr_input:
    arr[num + sz] += 1


m = int(input())
arr2 = list(map(int, input().split()))
for num in arr2:
    print(arr[num + sz], end=' ') 
    
---> 메모리 초과
"""

""" 
들어오는 값들에 대해서 정렬을 해야겠다.
"""

# 이진 탐색, 중복된 숫자가 있으므로
# 첫번째로 나오는 인덱스를 반환해야함
def binary_search(arr, num):
    # 초기에는 리스트의 시작과 끝으로 설정
    # idx는 값이 없는 경우 -1, 있는 경우 그 인덱스를 저장
    # 여러 개 있는 경우 개수를 세서 반환
    low, high = 0, len(arr) - 1
    idx = -1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < num:
            low = mid + 1
        elif arr[mid] > num:
            high = mid - 1
        else:
            # 값을 찾은 경우
            idx = mid
            break
    if idx == -1:
        return 0
    
    idx_left, idx_right = idx, idx
    if arr[idx] > arr[idx - 1] and arr[idx] < arr[idx + 1] and idx >= 0 and idx < len(arr) - 1:
        return 1
    while num == arr[idx_left] and idx_left >= 1:
        idx_left -= 1
    while num == arr[idx_right] and idx_right < len(arr) - 1:
        idx_right += 1
    
    return idx_right - idx_left

n = int(input())
arr_n = list(map(int, input().split()))

arr_n.sort()

m = int(input())
arr_m = list(map(int, input().split()))

for num in arr_m:
    print(binary_search(arr_n, num),end=' ')