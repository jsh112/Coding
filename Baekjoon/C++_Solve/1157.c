#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
char str[MAX];

int my_strlen(const char *s)
{
    const char *tmp = s;
    while (*tmp)
    {
        tmp++;
    }
    return tmp - s;
}

int main()
{
    scanf("%s", str);
    // Capital
    int alpha[26] = {0}, cap_to_small = 32, len = my_strlen(str);
    for (int idx = 0; idx < len; idx++)
    {
        char ch = str[idx];
        if (ch >= 'a' && ch <= 'z')
        {
            alpha[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            alpha[ch - 'A']++;
        }
    }
    int max = 0, cnt = 0;
    char c;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > max)
        {
            max = alpha[i];
            c = 'A' + i;
            cnt = 1;
        }
        else if (max == alpha[i])
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        printf("?");
    }
    else
    {

        printf("%c", c);
    }

    return 0;
}