#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return 0;
}

int my_atoi(const char *str)
{
    int number = 0, sign = 1;
    while (*str == ' ')
    {
        str++;
    }
    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        number = number * 10 + (*str - '0');
        str++;
    }

    return number * sign;
}

int check(char *s)
{
    if (!my_strcmp(s, "FizzBuzz") || !my_strcmp(s, "Fizz") || !my_strcmp(s, "Buzz"))
    {
        return 0;
    }
    return 1;
}
w int main()
{
    char s[3][10];
    int ans;
    scanf("%s %s %s", s, s + 1, s + 2);
    for (int i = 0; i < 3; i++)
    {
        if (check(s[i]))
        {
            ans = my_atoi(s[i]) + (3 - i);
        }
    }
    if (ans % 15 == 0)
    {
        printf("FizzBuzz");
    }
    else if (ans % 3 == 0)
    {
        printf("Fizz");
    }
    else if (ans % 5 == 0)
    {
        printf("Buzz");
    }
    else
    {
        printf("%d", ans);
    }

    return 0;
}