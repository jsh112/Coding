#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n, m;
    std::cin >> n >> m;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }

    int a, b;

    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        a -= 1;
        b -= 1;
        for (int j = a; j < (b + a + 1) / 2; j++)
        {
            int tmp = v[j];
            v[j] = v[b - j + a];
            v[b - j + a] = tmp;
        }
    }

    for (auto it : v)
    {
        std::cout << it << " ";
    }

    return 0;
}