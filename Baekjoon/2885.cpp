#include <iostream>
using namespace std;

int main()
{
    int n;
    std::cin >> n;
    int factor = 1, cnt = 0, sum;
    while (n > factor)
    {
        factor *= 2;
    }
    if (n == factor)
    {
        std::cout << factor << " " << cnt;
        return 0;
    }
    // 5 -> 101
    // 8개짜리 하나 사서
    // 반쪼개면 4 얘를 어딘가에 더하자
    // 반쪼개서 2 -> 얘를 더했을때 수를 넘어감 pass
    // 반쪼개서 1 -> 얘를 넣으면 정확히 같아짐
    int tmp = factor;
    while (1)
    {
        // sum이 n보다 작거나 같을때까지 하자
        n -= (tmp / 2);
        cnt++;
        if (n < 0)
        {
            // 다시 돌려놓자
            n += (tmp / 2);
        }
        else if (n == 0)
        {
            break;
        }
        tmp /= 2;
    }
    std::cout << factor << " " << cnt;
    return 0;
}