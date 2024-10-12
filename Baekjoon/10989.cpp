#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int arr[MAX];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, idx;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> idx;
        arr[idx]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}