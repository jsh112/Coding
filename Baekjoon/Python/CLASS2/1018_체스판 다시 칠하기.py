def color(board):
    sz = 8
    pattern1 = [['W' if (i + j) % 2 == 0 else 'B' for j in range(sz)] for i in range(sz)]
    pattern2 = [['B' if (i + j) % 2 == 0 else 'W' for j in range(sz)] for i in range(sz)]
    
    min_changes = float('inf')
    
    for r in range(len(board) - sz + 1):  
        for c in range(len(board[0]) - sz + 1):
            sub_board = [row[c:c+sz] for row in board[r:r+sz]]
    
            changes1 = sum(1 for i in range(sz) for j in range(sz) if sub_board[i][j] != pattern1[i][j])
            changes2 = sum(1 for i in range(sz) for j in range(sz) if sub_board[i][j] != pattern2[i][j])
            
            min_changes = min(min_changes, changes1, changes2)
    
    return min_changes

row, col = map(int, input().split())
board = [input().strip() for _ in range(row)]

print(color(board))
