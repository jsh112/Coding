#include <iostream>
#include <string>
#include <vector>
using namespace std;

void my_multiple(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    my_multiple(s1, s2);

    return 0;
}
