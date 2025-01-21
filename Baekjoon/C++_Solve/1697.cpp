#include <functional>
#include <iostream>
#include <queue>
#define MAX 100001

int visited[MAX];

int BFS(int& n, int& k) {
    std::queue<int> q;
    q.push(n);
    visited[n] = 0;

    std::function<int(int)> moves[] = {
        [](int x) { return x - 1; },
        [](int x) { return x + 1; },
        [](int x) { return x * 2; }};

    while (!q.empty()) {
        int CurPos = q.front();
        q.pop();

        if (CurPos == k)
            return visited[CurPos];

        for (const auto& move : moves) {
            int NextPos = move(CurPos);

            if (NextPos >= 0 && NextPos < MAX && visited[NextPos] == 0) {
                q.push(NextPos);
                visited[NextPos] = visited[CurPos] + 1;
            }
        }
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::cout << BFS(N, K);

    return 0;
}