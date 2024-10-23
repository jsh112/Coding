#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int K, N;
    std::cin >> K >> N;
    std::vector<unsigned int> v;
    unsigned int len;
    for (int i = 0; i < K; i++)
    {
        std::cin >> len;
        v.push_back(len);
    }

    sort(v.begin(), v.end());

    unsigned int start = 1;
    unsigned int end = v.back();
    unsigned int result = 0;

    while (start <= end)
    {
        int cnt = 0;
        unsigned int mid = (start + end) / 2;
        for (auto it : v)
            cnt += (it / mid);

        if (cnt >= N)
        {
            result = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    std::cout << result;
    return 0;
}