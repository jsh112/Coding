#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    while (getline(cin, s))
    {
        if (s == ".")
            break;

        if (s.back() != '.')
        {
            v.push_back("no");
            continue;
        }

        vector<char> stack;
        bool valid = true;

        for (char c : s)
        {
            if (c == '(' || c == '[')
            {
                stack.push_back(c);
            }
            else if (c == ')')
            {
                if (!stack.empty() && stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!stack.empty() && stack.back() == '[')
                {
                    stack.pop_back();
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        // 스택이 비어 있고 valid가 true여야 유효한 구조
        if (valid && stack.empty())
        {
            v.push_back("yes");
        }
        else
        {
            v.push_back("no");
        }
    }

    for (const auto &result : v)
    {
        cout << result << '\n';
    }

    return 0;
}