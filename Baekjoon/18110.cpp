#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{

    int n, op, sum = 0;
    std::cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        std::cin >> op;
        v.push_back(op);
    }
    sort(v.begin(), v.end());
    int exclude = (int)round(n * 0.15);
    if (exclude * 2 >= n)
    {
        cout << 0 << endl; // 남은 값이 없으므로 0 출력
        return 0;
    }
    for (int it = exclude; it < n - exclude; it++)
    {
        sum += v[it];
    }
    int count = n - 2 * exclude;
    std::cout << (int)round((float)sum / count) << std::endl;

    return 0;
}