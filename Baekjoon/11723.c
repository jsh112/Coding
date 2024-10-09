#include <stdio.h>
#define MAX 20
int my_strcmp(const char *_Str1, const char *_Str2);

int main()
{
    int m, elem, i = 0, cnt = 0;
    char str[10];
    scanf("%d", &m);
    int arr[21] = {
        0,
    };
    while (i != m)
    {
        scanf("%s %d", str, &elem);

        if (!my_strcmp(str, "add")){
            arr[elem] = 1;
        }
        else if (!my_strcmp(str, "remove")){
            arr[elem] = 0;
        }
        else if (!my_strcmp(str, "check"))
        {
            printf("%d\n", arr[elem]);
        }
        else if (!my_strcmp(str, "toggle"))
        {
            arr[elem] = !arr[elem];
        }
        else if (!my_strcmp(str, "all"))
        {
            for (int i = 1; i <= MAX; i++)
            {
                arr[i] = 1;
            }
        }
        else if (!my_strcmp(str, "empty"))
        {
            for (int i = 1; i <= MAX; i++)
            {
                arr[i] = 0;
            }
        }
        i++;
    }
    return 0;
}

int my_strcmp(const char *_Str1, const char *_Str2)
{
    while (*_Str1 == *_Str2)
    {
        if (!*_Str1 && !*_Str2)
        {
            return 0;
        }
        _Str1++;
        _Str2++;
    }
    return (*(unsigned char *)_Str1 > *(unsigned char *)_Str2) ? 1 : -1;
}