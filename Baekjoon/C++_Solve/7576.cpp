#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/**
 * BFS는 동시성을 가진다.
 * 익은 토마토가 두 개 이상일 경우에도,
 * 여러 출발점에서 동시에 탐색이 진행되므로
 * 여러 익은 토마토(1이 들어간 좌표들)를 모두 큐에 넣어 시작하면,
 * 각각의 경로에서 가장 빨리 익는 경로가 최단 경로가 된다.
 * 
 * 최소 일자를 구하는 과정에서,
 * 더 빨리 익히는 토마토의 영향을 받게 되므로,
 * 전체 토마토를 익히는 최소 일수를 구할 수 있게 된다.
 * 
 * 이미 익은 토마토에 의해 영향을 받은 토마토는,
 * 다른 출발점에서 시작한 토마토보다 더 빨리 익을 수 있다.
 * 
 * row와 col이 반대로 입력되므로 순서를 바꿔서 선언
 * isValid에서 중요한 것은 인덱스가 segfault가 되기 전에 예외처리를 하는 것
 * 예외가 아니라면(박스 안의 인덱스라면) 그 때의 값을 비교하는 것이다.
 */


int cols, rows;

bool isValid(std::vector<std::vector<int>>& vec, int rIdx, int cIdx) {
    return rIdx >= 0 && rIdx < rows && cIdx >= 0 && cIdx < cols && vec[rIdx][cIdx] == 0;
}

void BFS(std::vector<std::vector<int>>& vec) {
    int day = 0;
    std::queue<std::pair<int, int>> q;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(vec[i][j] == 1)
                q.push({i,j});
        }
    }

    std::vector<std::pair<int, int>> directions = {
        {0, -1},  
        {0, 1},   
        {-1, 0},  
        {1, 0}};  

    while (!q.empty()) {
        int qSize = q.size();   

        for (int i = 0; i < qSize; ++i) {
            std::pair<int, int> current = q.front();
            q.pop();
            int cur_r = current.first;
            int cur_c = current.second;

            for (const auto& dir : directions) {
                int new_r = cur_r + dir.first;
                int new_c = cur_c + dir.second;

                if (isValid(vec, new_r, new_c)) {
                    vec[new_r][new_c] = 1;  
                    q.push({new_r, new_c});
                }
            }
        }
        if(!q.empty())
            day++; 
    }

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (vec[i][j] == 0) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }
    std::cout << day << '\n'; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int num;
    std::cin >> cols >> rows;

    std::vector<std::vector<int>> vec(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> num;
            vec[i][j] = num;
        }
    }

    BFS(vec);

    return 0;
}