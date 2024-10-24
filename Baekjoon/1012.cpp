#include <iostream>
#include <queue>
#include <vector>

/**
 * BFS를 사용하는 문제
 * 배추가 1, 안심어진 땅이 0이므로
 * 방문한 곳들을 2로 만들어서 queue에 들어가지 않게 함
 * 즉, 일찍 찾은 뭉치들은 다 2로 바뀌어버려서 1을 찾을 때 배제
 * 그렇다면 내가 1을 찾을때마다 새로운 덩어리이므로 ++을 해주면 된다
 * 1이 한칸만 있을때에도 미리 +1을 해놓았기 때문에 예외가 없음
 * row, col을 전역변수로 해놔야 행, 열의 size가 바뀌어도 바로 참조가 가능
 */

int cols, rows;

bool isValid(std::vector<std::vector<int>>& vec, int r, int c) {
    return ((r >= 0 && r < rows) && (c >= 0 && c < cols) && vec[r][c] == 1);
}

void BFS(std::vector<std::vector<int>>& vec, int i, int j) {
    std::queue<std::pair<int, int>> q;
    vec[i][j] = 2;
    q.push({i, j});

    std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int cur_r = current.first;
        int cur_c = current.second;
        for (auto dir : directions) {
            int new_r = cur_r + dir.first;
            int new_c = cur_c + dir.second;

            if (isValid(vec, new_r, new_c)) {
                vec[new_r][new_c] = 2;
                q.push({new_r, new_c});
            }
        }
    }
}

void find_area(std::vector<std::vector<int>>& vec, int row, int col) {
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (vec[i][j] == 1) {
                cnt++;
                BFS(vec, i, j);
            }
        }
    }
    std::cout << cnt << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    int num;
    int y, x;
    for (int i = 0; i < t; i++) {
        std::cin >> cols >> rows >> num;
        std::vector<std::vector<int>> vec(rows, std::vector<int>(cols, 0));

        for (int j = 0; j < num; j++) {
            std::cin >> y >> x;
            vec[x][y] = 1;
        }

        find_area(vec, rows, cols);
    }

    return 0;
}