#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(std::vector<int>& map) {
    std::queue<int> q;
    q.push(1);

    std::vector<bool> visited(101, false);
    visited[1] = true;

    int cnt = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int idx = q.front();
            q.pop();

            if (idx == 100) {
                std::cout << cnt;
                return;
            }

            for (int dice = 1; dice < 7; dice++) {
                int next = idx + dice;
                if (next <= 100) {
                    if (map[next] != 0)
                        next = map[next];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cnt++;
    }
}

int main() {
    int lad, snake;
    std::cin >> lad >> snake;
    std::vector<int> map(101, 0);

    int start, end;
    for (int i = 0; i < (lad + snake); i++) {
        std::cin >> start >> end;
        map[start] = end;
    }

    BFS(map);
    return 0;
}