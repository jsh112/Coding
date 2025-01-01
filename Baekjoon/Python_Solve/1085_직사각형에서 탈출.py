""" 
(x, y)에서 최소 거리로 직사각형의 경계선에 도달하는 거리
min_x = x if x < w // 2 else w - x
"""

x, y, w, h = map(int,input().split())

min_x = min(x, w - x)
min_y = min(y, h - y)

print(min(min_x, min_y))