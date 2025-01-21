#include <iostream>
using namespace std;
int main()
{
    unsigned int a, b, c;
    std::cin >> a >> b >> c;

    unsigned int k = a ^ b;
    if (c % 2 == 0)
    {
        k ^= b;
    }
    std::cout << k;
    return 0;
}