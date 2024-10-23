#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n, sum = 0;
    std::cin >> n >> str;

    for (char c : str)
    {
        sum += (c == '1');
    }
    std::cout << sum;
    return 0;
}