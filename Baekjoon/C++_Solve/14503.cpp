#include <iostream>
#include <string>
using namespace std;

// N이 입력되면 N번째 종말의 수를 출력
// "666"이 들어가면 종말의 수가 된다.

int find_string(const std::string &s, const std::string &want)
{
    return s.find(want) != std::string::npos ? 1 : 0;
}

void my_itoa(string &s, int k)
{
    s.clear();

    int factor = 1;
    int tmp = k;
    while (tmp >= 10)
    {
        factor *= 10;
        tmp /= 10;
    }

    while (factor > 0)
    {
        int digit = k / factor;
        s.push_back('0' + digit);
        k %= factor;
        factor /= 10;
    }
}

int main()
{
    int n;
    std::string s, want = "666";
    std::cin >> n;
    int cnt = 0, k = 665;

    while (cnt < n)
    {
        k++;
        my_itoa(s, k);
        cnt += find_string(s, want);
    }

    std::cout << k;
    return 0;
}
