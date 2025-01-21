#include <iostream>
using namespace std;

int main()
{

    unsigned long long n;
    std::cin >> n;

    int cnt = 0;
    while (n % 2 == 0)
    {
        cnt++;
        n >>= 1;
    }
    std::cout << 64 - cnt;
    return 0;
}