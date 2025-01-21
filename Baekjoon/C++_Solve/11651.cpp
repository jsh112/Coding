#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    std::vector<std::pair<int, int>> v;
    std::cin >> n;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        v.push_back(std::make_pair(x, y));
    }

    std::sort(v.begin(), v.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
              {
        if (a.second < b.second)
            return true;  // Sort primarily by second element
        else if (a.second == b.second)
            return a.first < b.first;  // If second elements are equal, sort by first element
        return false; });

    for (auto it : v)
    {
        std::cout << it.first << " " << it.second << "\n";
    }

    return 0;
}