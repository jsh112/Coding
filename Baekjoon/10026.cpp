#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void bfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int x, int y, bool isColorblind) {
    int sz = grid.size();
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    std::pair<int, int> dirs[4] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    char current_color = grid[x][y];

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;

        for (auto dir : dirs) {
            int new_x = cur_x + dir.first;
            int new_y = cur_y + dir.second;

            if (new_x >= 0 && new_x < sz && new_y >= 0 && new_y < sz && !visited[new_x][new_y]) {
                // 적록색맹의 경우 R과 G를 동일하게 취급
                if (isColorblind) {
                    if ((current_color == 'R' || current_color == 'G') && (grid[new_x][new_y] == 'R' || grid[new_x][new_y] == 'G')) {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    } else if (current_color == 'B' && grid[new_x][new_y] == 'B') {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                } else {
                    // 색깔이 같은 경우에만 탐색
                    if (grid[new_x][new_y] == current_color) {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
    }
}

int FindSection(std::vector<std::vector<char>>& grid, int sz, bool isColorblind) {
    std::vector<std::vector<bool>> visited(sz, std::vector<bool>(sz, false));
    int count = 0;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (!visited[i][j]) {
                bfs(grid, visited, i, j, isColorblind);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int sz;
    std::cin >> sz;
    std::string str;
    std::vector<std::vector<char>> grid(sz, std::vector<char>(sz));

    for (int i = 0; i < sz; i++) {
        std::cin >> str;
        for (int j = 0; j < sz; j++) {
            grid[i][j] = str[j];
        }
    }

    // 적록색맹이 아닌 사람
    int normalCount = FindSection(grid, sz, false);
    // 적록색맹
    int colorblindCount = FindSection(grid, sz, true);

    std::cout << normalCount << " " << colorblindCount << "\n";

    return 0;
}
