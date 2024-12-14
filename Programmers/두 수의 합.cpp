#include <iostream>
#include <string>
using namespace std;

std::string solution(std::string a, std::string b) {
    std::string ans;
    int carry = 0;

    if (a.length() < b.length())
        // a가 짧은 경우
        a.insert(a.begin(), b.length() - a.length(), '0');
    else if (a.length() > b.length())
        b.insert(b.begin(), a.length() - b.length(), '0');

    int i = a.length() - 1;
    for (; i >= 0; --i) {
        int num1 = a[i] - '0';
        int num2 = b[i] - '0';
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        ans.insert(ans.begin(), (sum % 10) + '0');
    }
    if (carry)
        ans.insert(ans.begin(), carry + '0');

    return ans;
}

int main(int argc, char *argv[]) {
    std::string a, b;
    std::cin >> a >> b;

    std::cout << solution(a, b);

    return 0;
}