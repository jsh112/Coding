#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    std::cin >> s;
    // + s.length()
    int time = 0;
    for (char c : s)
    {
        // 0,1,2 -> 1
        // 3,4,5 -> 2
        // (c - 'A') / 3 + 1
        if (c < 'P')
        {
            time += (c - 'A') / 3 + 2;
        }
        else if (c < 'T')
        {
            time += 7;
        }
        else if (c < 'W')
        {
            time += 8;
        }
        else
        {
            time += 9;
        }
    }
    std::cout << time + s.length() << std::endl;
    return 0;
}