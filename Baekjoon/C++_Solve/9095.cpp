#include <iostream>

int arr[11] = {1, 1, 2};

void sum()
{
    for (int i = 3; i < 11; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
}

int main()
{

    int T, num;
    std::cin >> T;
    sum();
    while (T--)
    {
        std::cin >> num;
        std::cout << arr[num] << '\n';
    }

    return 0;
}