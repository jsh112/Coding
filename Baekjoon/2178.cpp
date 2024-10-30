#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solvemaze(std::vector<std::vector<int>>& maze, int e_x, int e_y) {
    int rows = e_x + 1;
    int cols = e_y + 1;

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, 0));
    visited[0][0] = true;
    distance[0][0] = 1;

    std::pair<int, int> dirs[4] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    while (!q.empty()) {
        auto cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        q.pop();

        if (cur_x == e_x && cur_y == e_y) {
            std::cout << distance[cur_x][cur_y] << "\n";
            return;
        }

        for (auto d : dirs) {
            int new_x = cur_x + d.first;
            int new_y = cur_y + d.second;

            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols &&
                maze[new_x][new_y] == 1 && !visited[new_x][new_y]) {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;                         
                distance[new_x][new_y] = distance[cur_x][cur_y] + 1;  
            }
        }
    }
}

int main() {
    int n, m;
    std::string str;
    std::cin >> n >> m;
    std::vector<std::vector<int>> maze(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        std::cin >> str;
        for (int j = 0; j < m; j++) {
            maze[i][j] = (str[j] - '0');
        }
    }
    n--;
    m--;

    solvemaze(maze, n, m);

    return 0;
}