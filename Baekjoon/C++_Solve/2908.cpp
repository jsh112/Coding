#include <iostream>
#include <string>
using namespace std;

void func(const string &s1, const string &s2)
{
    int fact_s1 = 1, fact_s2 = 1, sum_s1 = 0, sum_s2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum_s1 += fact_s1 * (s1[i] - '0');
        fact_s1 *= 10;
    }
    for (int i = 0; i < 3; ++i)
    {
        sum_s2 += fact_s2 * (s2[i] - '0');
        fact_s2 *= 10;
    }

    std::cout << ((sum_s1 > sum_s2) ? sum_s1 : sum_s2) << std::endl;
}

int main()
{
    string s1, s2;
    std::cin >> s1 >> s2;
    func(s1, s2);

    return 0;
}