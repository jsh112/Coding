#include <stdio.h>
#include <stdlib.h>
#define MAX 500001

int n, m;
int arr[MAX], src[MAX];

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // 간결하게 변경
}

void Input_arr(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    qsort(arr, n, sizeof(int), cmp);
}

void binary(int *arr, int val, int size)
{
    int start = 0, end = size, mid, tmp;
    // 시작점 찾기
    while (start < end)
    {
        mid = (start + end) / 2;
        arr[mid] > val ? end = mid : (start = mid + 1);
    }
    tmp = end;
    start = 0, end = size;
    while (start < end)
    {
        mid = (start + end) / 2;
        arr[mid] >= val ? (end = mid) : (start = mid + 1);
    }
    printf("%d ", tmp - end);
}

int main()
{
    Input_arr();
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &src[i]);
        binary(arr, src[i], n);
    }
    return 0;
}
