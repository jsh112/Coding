#include <iostream>
using namespace std;

int main()
{

    int x, n, a, b, sum = 0;
    std::cin >> x;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        x -= a * b;
    }
    if (sum == x)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}