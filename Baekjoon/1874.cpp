#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, num, current = 1;
    cin >> n;
    vector<int> v(n), tmp;
    vector<char> ans;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        while (current <= v[i])
        {
            tmp.push_back(current++);
            ans.push_back('+');
        }
        if (tmp.empty() || tmp.back() != v[i])
        {
            cout << "NO" << endl;
            return 0;
        }
        tmp.pop_back();
        ans.push_back('-');
    }

    for (char c : ans)
        cout << c << '\n';

    return 0;
}
