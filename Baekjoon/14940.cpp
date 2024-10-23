#include <iostream>
#include <queue>
#include <vector>

int rows, cols;

bool isValid(std::vector<std::vector<int>>& flag, int c_r, int c_c) {
    return c_r >= 0 && c_r < rows && c_c >= 0 && c_c < cols && flag[c_r][c_c] == 0;
}

void BFS(std::vector<std::vector<int>>& vec, std::vector<std::vector<int>>& flag, int start_r, int start_c) {
    std::queue<std::pair<int, int>> q;
    q.push({start_r, start_c});
    flag[start_r][start_c] = -1;
    vec[start_r][start_c] = 0;

    std::vector<std::pair<int, int>> directions = {
        {-1, 0},  
        {1, 0},   
        {0, -1},  
        {0, 1}    
    };

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();
        int cur_r = current.first;
        int cur_c = current.second;
        int current_dist = vec[cur_r][cur_c];

        for (const auto& dir : directions) {
            int new_r = cur_r + dir.first;
            int new_c = cur_c + dir.second;

            if (isValid(flag, new_r, new_c)) {
                vec[new_r][new_c] = current_dist + 1;
                flag[new_r][new_c] = -1;
                q.push({new_r, new_c});
            }
        }
    }
}

void find_way(std::vector<std::vector<int>>& vec, std::vector<std::vector<int>>& flag) {
    // find start point
    int start_row = -1, start_col = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (vec[i][j] == 2) {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row != -1)
            break;
    }
    int dist = 0;
    BFS(vec, flag, start_row, start_col);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> rows >> cols;
    std::vector<std::vector<int>> vec(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> flag_vec(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> vec[i][j];
            if (!vec[i][j])
                flag_vec[i][j] = 1;
        }
    }
    find_way(vec, flag_vec);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (flag_vec[i][j] == 1) {
                vec[i][j] = 0;
            } else if (flag_vec[i][j] == 0)
                vec[i][j] = -1;
            std::cout << vec[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}