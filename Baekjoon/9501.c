#include <stdio.h>

int main()
{

    int t, n, d;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int cnt = 0;
        scanf("%d %d", &n, &d);
        for (int j = 0; j < n; j++)
        {
            int v, f, c;
            scanf("%d %d %d", &v, &f, &c);
            if (v * f / c >= d)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}