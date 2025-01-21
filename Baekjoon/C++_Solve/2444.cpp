#include <iostream>
using namespace std;

int main()
{
    int n, i;
    std::cin >> n;
    int duration = n;
    for (i = 1; i < 2 * n; i += 2)
    {
        for (int j = 1; j < duration; j++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }

        duration--;
        std::cout << '\n';
    }
    duration = 1;
    i -= 2 * 2;
    for (; i >= 1; i -= 2)
    {
        for (int j = duration; j >= 1; j--)
        {
            std::cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }

        duration++;
        std::cout << '\n';
    }

    return 0;
}