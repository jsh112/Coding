#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, num;
    vector<int> v;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << '\n';
    }

    return 0;
}