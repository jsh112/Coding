#include <iostream>
using namespace std;

int main()
{
    int time, min, plus;
    std::cin >> time >> min;
    std::cin >> plus;
    // minute
    min += plus;
    while (min >= 60)
    {
        time++;
        min -= 60;
    }
    while (time >= 24)
    {
        time -= 24;
    }
    std::cout << time << " " << min << std::endl;

    return 0;
}