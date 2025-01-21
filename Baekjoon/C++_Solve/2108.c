#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 8001
#define Zero 4000
#define T 500001
int arr_duration[MAX];
int arr_num[T];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int duration, sum = 0, max = -4000, min = 4000, num;
    scanf("%d", &duration);
    for (int i = 0; i < duration; i++)
    {
        scanf("%d", &num);
        arr_duration[Zero + num]++;
        // median
        arr_num[i] = num;
        // mean
        sum += num;
        // 범위
        if (max < num)
        {
            max = num;
        }
        if (min > num)
        {
            min = num;
        }
    }
    int maxCount = 0;
    int first_mode = 0, second_mode = 0;
    int mode_cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (arr_duration[i] > maxCount)
        {
            maxCount = arr_duration[i];
            first_mode = i - Zero;
            second_mode = 0;
            mode_cnt = 1;
        }
        else if (arr_duration[i] == maxCount)
        {
            if (mode_cnt == 1)
            {
                second_mode = i - Zero;
                mode_cnt = 2;
            }
        }
    }
    qsort(arr_num, duration, sizeof(int), cmp);

    printf("%d\n", (int)round((float)sum / (float)duration));
    printf("%d\n", arr_num[duration / 2]);
    printf("%d\n", mode_cnt == 1 ? first_mode : second_mode);
    printf("%d\n", max - min);
    return 0;
}