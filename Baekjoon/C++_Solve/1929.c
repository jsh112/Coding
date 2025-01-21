#include <stdio.h>
#define MAX 10000001

int arr[MAX];

void Prime(int _m, int _n)
{
    arr[1] = 1;
    for (int i = 2; i * i <= _n; i++)
    {
        if (arr[i])
        {
            continue;
        }
        for (int j = 2; j * i <= _n; j++)
        {
            arr[i * j] = 1;
        }
    }
    for (int i = _m; i <= _n; i++)
    {
        if (!arr[i])
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Prime(m, n);

    return 0;
}