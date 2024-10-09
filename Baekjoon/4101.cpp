#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while (true)
    {
        std::cin >> n >> m;
        if (!n && !m)
        {
            break;
        }
        std::cout << (n > m ? "Yes" : "No") << std::endl;
    }

    return 0;
}