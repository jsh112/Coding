def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if (x[0] <= pivot[0]) and (x[1] <= pivot[1])]
    right = [x for x in arr if (x[0] >= pivot[0]) and (x[1] >= pivot[1])]
    
    return quick_sort(left) + [pivot] + quick_sort(right)

n = int(input())

tu = []
for i in range(n):
    w, h = map(int, input().split())
    tu.append([w, h, i])  # (몸무게, 키, 인덱스)


rank = [0] * n
# r1은 사람 수, r2는 출력할 등수
r1, r2 = 1, 1
""" 
1, 1
-> 2, 2

동률
2 2
3, 2

동률
4, 2
2 2

큼
5, 2

"""

arr = quick_sort(tu)

for i in range(len(arr)-1,0,-1):
    w1, h1, idx1 = arr[i]
    w2, h2, idx2 = arr[i - 1]
    
    # 덩치가 큰 경우
    if w1 > w2 and h1 > h2:
        # 처음 시작하는 경우
        if i == len(arr) - 1:
            rank[idx1] = r1
            r1 += 1
            r2 += 1
            rank[idx2] = r1
        else:
            r1 += 1
            rank[idx2] = r1
    # 덩치가 같은 경우
    else:
        rank[idx1] = rank[idx2] = r2
        r1 += 1
        
print(rank)