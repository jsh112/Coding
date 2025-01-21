#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int k, num, sum = 0;
    std::cin >> k;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        std::cin >> num;
        if (num != 0)
        {
            v.push_back(num);
        }
        else
        {
            v.pop_back();
        }
    }

    vector<int>::iterator it = v.begin();
    for (; it != v.end(); it++)
    {
        sum += *it;
    }
    std::cout << sum;

    return 0;
}