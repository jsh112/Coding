""" 
M x N 보드에서 8 x 8로 잘랐을 때
검은색과 흰색이 번갈아져서 칠해져야 한다는 규칙이 있고,
최소한으로 바꿔야 하는 픽셀의 개수를 구하여라
M, N은 모두 8보다 크다.

좌상단이 B이거나 W일 때 8 x 8 체스판은 규칙을 가진다.
즉, 인덱스를 가지고 패턴과 다른 경우의 픽셀을 카운트하면 될거같다.
"""

def color(board):
    row = len(board)
    col = len(board[0])
    sz = 8
    pixel = sz * sz
    
    pattern1 = [['W' if (i + j) % 2 == 0 else 'B' for i in range(sz)] for j in range(sz)]
    pattern2 = [['B' if (i + j) % 2 == 0 else 'W' for i in range(sz)] for j in range(sz)]
    
    for r in range(row - sz + 1):
        for c in range(col - sz + 1):
            test_board = [board[i][c:c+sz] for i in range(r, r+sz)]
            count_pat1 = 0
            count_pat2 = 0
            
            for i in range(sz):
                for j in range(sz):
                    if test_board[i][j] != pattern1[i][j]:
                        count_pat1 += 1
                    if test_board[i][j] != pattern2[i][j]:
                        count_pat2 += 1
            
            count_pixel = min(count_pat1, count_pat2)
            # 패턴을 통해서 찾고, 픽셀을 업데이트
            if count_pixel < pixel:
                pixel = count_pixel
    return pixel

row, col = map(int, input().split())
board = [input().strip() for _ in range(row)]

print(color(board))

""" print()
for item in board:
    print(*item) """