#include <iostream>
#include <algorithm>
using namespace std;

void dice(int d1, int d2, int d3)
{
    int arr[3] = {d1, d2, d3};
    sort(arr, arr + 3);

    if (arr[0] == arr[2]) // 모두 같은 경우
    {
        cout << 10000 + arr[0] * 1000 << endl;
    }
    else if (arr[0] == arr[1] || arr[1] == arr[2]) // 두 개가 같은 경우
    {
        cout << 1000 + arr[1] * 100 << endl;
    }
    else // 모두 다른 경우
    {
        cout << arr[2] * 100 << endl;
    }
}

int main()
{
    int d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;

    dice(d1, d2, d3);
    return 0;
}