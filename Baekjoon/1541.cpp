#include <iostream>
#include <string>
#include <vector>
using namespace std;

void make_parantheses(std::string& str) {
    std::vector<int> num;
    std::vector<char> _operator;

    int sum = 0;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            sum = 10 * sum + (c - '0');
        } else {
            _operator.push_back(c);
            num.push_back(sum);
            sum = 0;
        }
    }
    num.push_back(sum);
    // num -> number
    // _operator -> '+', '-'

    int print = num[0];
    for (int i = 0; i < _operator.size(); i++) {
        if (_operator[i] == '-' && _operator[i + 1] == '+' && i + 1 < _operator.size())
            _operator[i + 1] = '-';

        if (_operator[i] == '+')
            print += num[i + 1];
            
        else
            print -= num[i + 1];
    }
    std::cout << print;
}

int main() {
    std::string str;
    std::cin >> str;

    make_parantheses(str);

    return 0;
}