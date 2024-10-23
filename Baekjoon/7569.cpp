#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int col, row, height;

bool isValid(std::vector<std::vector<std::vector<int>>>& vec, int h, int r, int c) {
    return (h >= 0 && h < height) && (r >= 0 && r < row) && (c >= 0 && c < col) && vec[h][r][c] == 0;
}

void BFS(std::vector<std::vector<std::vector<int>>>& tomato) {
    int day = 0;
    std::queue<std::tuple<int, int, int>> q;

    // 익은 토마토(1)가 있는 좌표를 모두 큐에 넣음
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                if (tomato[i][j][k] == 1)
                    q.push({i, j, k});
            }
        }
    }

    std::vector<std::tuple<int, int, int>> directions = {
        {0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};

    while (!q.empty()) {
        int qSize = q.size();
        bool progress = false;  

        for (int i = 0; i < qSize; ++i) {
            std::tuple<int, int, int> current = q.front();
            q.pop();

            int cur_h = std::get<0>(current);
            int cur_r = std::get<1>(current);
            int cur_c = std::get<2>(current);

            for (const auto& dir : directions) {
                int new_h = cur_h + std::get<0>(dir);
                int new_r = cur_r + std::get<1>(dir);
                int new_c = cur_c + std::get<2>(dir);

                if (isValid(tomato, new_h, new_r, new_c)) {
                    tomato[new_h][new_r][new_c] = 1;
                    q.push({new_h, new_r, new_c});
                    progress = true; 
                }
            }
        }

        if (progress)
            day++;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                if (tomato[i][j][k] == 0) {
                    std::cout << -1 << '\n';  
                    return;
                }
            }
        }
    }

    std::cout << day << '\n';
}


int main() {
    std::cin >> col >> row >> height;
    int num;

    std::vector<std::vector<std::vector<int>>> tomato;
    tomato.resize(height, std::vector<std::vector<int>>(row, std::vector<int>(col)));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                std::cin >> num;
                tomato[i][j][k] = num;
            }
        }
    }
    BFS(tomato);

    return 0;
}