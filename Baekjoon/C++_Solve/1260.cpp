#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int node, edge, StartVet;

void DFS(std::vector<std::vector<int>>& g, std::vector<int>& visit, int start) {
    std::stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        // 현재 노드를 방문하고 출력
        if(visit[cur] == 0)
            std::cout << cur << " ";
        visit[cur] = 1;

        // 현재 노드의 인접 노드들을 역순으로 탐색
        for (auto it = g[cur].rbegin(); it != g[cur].rend(); ++it) {
            if (visit[*it] == 0) {
                st.push(*it);
            }
        }
    }
    std::cout << "\n";
}


// BFS
void BFS(std::vector<std::vector<int>>& g, std::vector<int>& visit, int start) {
    std::queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        visit[cur] = 1;
        std::cout << cur << " ";
        q.pop();

        for (auto n : g[cur]) {
            if (visit[n] == 0) {
                q.push(n);
                // 방문 예정
                visit[n] = 1;
            }
        }
    }
}

// DFS

int main() {
    std::cin >> node >> edge >> StartVet;
    std::vector<int> visit_dfs(node + 1, 0);
    std::vector<int> visit_bfs(node + 1, 0);

    std::vector<std::vector<int>> graph(node + 1);

    int src, dest;
    for (int i = 0; i < edge; i++) {
        std::cin >> src >> dest;
        // src번째 node에 도착지를 벡터에 삽입
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    for (auto& it : graph) {
        std::sort(it.begin(), it.end(), [](const int& a, const int& b) {
            return a < b;
        });
    }
    DFS(graph, visit_dfs, StartVet);
    BFS(graph, visit_bfs, StartVet);

    /* for(auto it : graph){
        for(int i=0;i<it.size();i++){
            std::cout<<it[i]<<" ";
        }
        std::cout<<'\n';
    } */

    return 0;
}