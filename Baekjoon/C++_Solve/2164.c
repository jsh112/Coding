#include <stdio.h>

void card(int n)
{
    if ((n & (n - 1)) == 0)
    {
        printf("%d\n", n);
    }
    else
    {
        int i = 1;
        while (n > i)
        {
            i *= 2;
        }
        printf("%d\n", (n - i / 2) * 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    card(n);

    return 0;
}