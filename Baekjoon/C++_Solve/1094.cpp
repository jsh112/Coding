#include <iostream>
using namespace std;

int main()
{

    int x, cnt = 0;
    std::cin >> x;

    while (x != 0)
    {
        if (x & 0x01)
        {
            cnt++;
        }
        x >>= 1;
    }
    std::cout << cnt;
    return 0;
}