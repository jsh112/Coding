#include <stdio.h>
#include <stdlib.h>

int n, m, b;

int compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
    {
        return 1;
    }
    else if (*(int *)first < *(int *)second)
    {
        return -1;
    }
    else
        return 0;
}

void print_result(int *arr, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            printf("1\n");
            return;
        }
        else if (arr[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    printf("0\n");
}

int main()
{
    scanf("%d", &n);
    int a[100000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        print_result(a, b);
    }
    return 0;
}