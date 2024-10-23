#include <iostream>
#include <vector>
#include <queue>

void dfs(int node, int n_cc, std::vector<std::vector<int>> &graph, std::vector<int> &cc)
{
    cc[node] = n_cc;
    for (int neighbor : graph[node])
    {
        if (!cc[neighbor])
            dfs(neighbor, n_cc, graph, cc);
    }
}

void bfs(int start_node, int n_cc, const std::vector<std::vector<int>> &graph, std::vector<int> &cc)
{
    std::queue<int> q;
    q.push(start_node);
    cc[start_node] = n_cc;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int neighbor : graph[cur])
        {
            if (!cc[neighbor])
            {
                cc[neighbor] = n_cc;
                q.push(neighbor);
            }
        }
    }
}

int main()
{

    int n, m, src, dest;
    std::cin >> n >> m;
    std::vector<std::vector<int>> node(n);
    std::vector<int> cc(n, 0);
    int n_cc = 0;

    for (int i = 0; i < m; i++)
    {
        std::cin >> src >> dest;
        node[src - 1].push_back(dest - 1);
        node[dest - 1].push_back(src - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (!cc[i])
        {
            n_cc++;
            bfs(i, n_cc, node, cc);
        }
    }

    std::cout << n_cc;
    return 0;
}