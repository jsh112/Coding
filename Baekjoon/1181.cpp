#include <iostream>
#include <algorithm>
using namespace std;

string str[20000];

int my_strcmp(string str1, string str2)
{
    if (str1.length() == str2.length())
    {
        return str1 < str2;
    }
    else
    {
        return str1.length() < str2.length();
    }
}

int main()
{

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    sort(str, str + N, my_strcmp);

    for (int i = 0; i < N; i++)
    {
        if (str[i] == str[i - 1])
        {
            continue;
        }
        std::cout << str[i] << "\n";
    }

    return 0;
}
