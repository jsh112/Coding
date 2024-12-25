""" 
(x, y) (p, q)
case1. x > p and y > q -> 덩치가 크다
case2. x < p and y < q -> 덩치가 작다
N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다. 
만일 "자신보다 더 큰 덩치의 사람이 k명이라면" 그 사람의 덩치 등수는 k+1이 된다. 
이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다.

-> 정렬을 해야하는데, 등수 표기는 초기 입력값 순서이므로
(weight, height, idx)로 저장하자
"""

""" def quick_sort(arr): 
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    
    left = [x for x in arr if x[0] < pivot[0] and x[1] < pivot[1]]
    right = [x for x in arr if x[0] > pivot[0] and x[1] > pivot[1]]
    middle = [x for x in arr if x not in left and x not in right]
    
    return quick_sort(left) + middle + quick_sort(right)


N = int(input())
people = [list(map(int, input().split())) + [i] for i in range(N)]

people = quick_sort(people)

rank = [1] * N

# 뒤에서부터 순위를 매김
do_rank = 1
for i in range(len(people)-1, 0, -1):
    w1, h1, idx1 = people[i]
    w2, h2, idx2 = people[i - 1]
    
    
    # 덩치가 큰 경우
    if w1 > w2 and h1 > h2:
        rank[idx2] = do_rank
    # 정렬을 했으므로 덩치가 크거나 같은 경우만 존재
    elif (w1 > w2 and h1 < h2) or (w1 < w2 and h1 > h2):
        rank[idx2] = rank[idx1]
        do_rank += 1
    do_rank += 1
        
print(*rank) """

N = int(input())
people = [list(map(int, input().split())) for _ in range(N)]

# 순위 계산
for i in range(N):
    rank = 1
    for j in range(N):
        if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
            rank += 1
    print(rank, end=' ')
