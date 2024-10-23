#include <iostream>
using namespace std;

int main()
{

    unsigned int N;
    std::cin >> N;
    if (N == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    while (N != 1)
    {
        if ((N & 0x01) != 0)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
        N >>= 1;
    }
    std::cout << 1 << std::endl;
    return 0;
}