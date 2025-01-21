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
char num[100];
int idx = 0;

int main()
{

    unsigned long long n;
    int b, mod;

    scanf("%lld %d", &n, &b);
    while (n != 0)
    {
        mod = n % b;
        if (mod >= 10)
        {
            num[idx++] = 'A' + mod - 10;
        }
        else
        {
            // 주의
            num[idx++] = mod + '0';
        }
        n /= b;
    }
    for (int i = idx - 1; i >= 0; i--)
    {
        printf("%c", num[i]);
    }

    return 0;
}