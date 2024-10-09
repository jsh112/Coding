#include <stdio.h>
#include <stdlib.h>

typedef struct cartesian
{
    int x;
    int y;
} c;

int compare(const void *a, const void *b)
{
    c *c1 = (c *)a;
    c *c2 = (c *)b;

    if (c1->x != c2->x)
    {
        return c1->x - c2->x;
    }
    else
    {
        return c1->y - c2->y;
    }
}

int main()
{
    int n, tmp_x, tmp_y;
    scanf("%d", &n);
    c coord[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coord[i].x, &coord[i].y);
    }

    qsort(coord, n, sizeof(c), compare);

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", coord[i].x, coord[i].y);
    }

    return 0;
}