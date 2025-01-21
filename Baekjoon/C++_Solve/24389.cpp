#include <iostream>

int main()
{

    unsigned int n, c_n;
    std::cin >> n;
    c_n = ~n + 1;

    int cnt = 0;

    for (int i = 0; i < 32; i++)
    {
        int a = n & 0x01;
        int b = c_n & 0x01;
        if (a != b)
        {
            cnt++;
        }
        n >>= 1;
        c_n >>= 1;
    }
    std::cout << cnt;

    return 0;
}