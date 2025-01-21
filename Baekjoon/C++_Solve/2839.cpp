#include <iostream>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    int k1, k2, bags = -1;
    k1 = n / 5;
    do
    {
        k2 = n - 5 * k1;
        if (k2 % 3 == 0)
        {
            bags = k1 + k2 / 3;
            std::cout << bags;
            return 0;
        }
        k1--;
    } while (k1 >= 0);
    std::cout << bags;

    return 0;
}