#include <stdio.h>

int my_strlen(char *s)
{
    char *tmp = s;
    while (*tmp)
    {
        tmp++;
    }
    return tmp - s;
}

int main()
{

    char num[50];
    int b;
    unsigned long long p = 0;
    scanf("%s %d", num, &b);
    int len = my_strlen(num), factor = 1, tmp;
    for (int i = len - 1; i >= 0; i--)
    {
        tmp = num[i] - '0';
        if (tmp < 10)
        {
            p += tmp * factor;
        }
        else
        {
            p += (num[i] - 'A' + 10) * factor;
        }
        factor *= b;
    }
    printf("%lld", p);

    return 0;
}