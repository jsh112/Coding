#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n_com, connect, c1, c2;
    std::cin >> n_com >> connect;
    std::vector<std::vector<int>> vecArr(n_com);
    std::vector<bool> victim(n_com, false);

    for (int i = 0; i < connect; i++)
    {
        std::cin >> c1 >> c2;
        vecArr[c1 - 1].push_back(c2 - 1);
        vecArr[c2 - 1].push_back(c1 - 1);
    }

    int victed_cnt = 0;

    std::queue<int> q;
    victim[0] = true;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        victed_cnt++;

        for (int connected_com : vecArr[cur])
        {
            if (!victim[connected_com])
            {
                victim[connected_com] = true;
                q.push(connected_com);
            }
        }
    }
    std::cout << victed_cnt - 1;

    return 0;
}