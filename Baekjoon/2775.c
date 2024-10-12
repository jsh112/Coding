#include <stdio.h>

int main()
{

    int t, k, n, people[15][15];
    scanf("%d", &t);
    // 0층부터 채우자
    for (int room = 1; room < 15; room++)
    {
        people[0][room] = room;
    }

    for (int floor = 1; floor < 15; floor++)
    {
        for (int room = 1; room < 15; room++)
        {
            if (room == 1)
            {
                people[floor][room] = 1;
            }
            else
            {
                people[floor][room] = people[floor - 1][room] + people[floor][room - 1];
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", people[k][n]);
    }

    return 0;
}