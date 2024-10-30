def find_non_intersecting_segments(N, points):
    segments = []
    for i, (x, y) in enumerate(points):
        # 새로운 점을 주어진 점의 대칭 위치에 생성
        new_x = -x
        new_y = -y
        segments.append((i + 1, new_x, new_y))
    return segments

# 입력 받기
T = int(input().strip())
results = []
for _ in range(T):
    N = int(input().strip())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    result = find_non_intersecting_segments(N, points)
    results.append(result)

# 출력
for result in results:
    for p_j, x_j, y_j in result:
        print(p_j, x_j, y_j)
