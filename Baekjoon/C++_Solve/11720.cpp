#include <iostream>
using namespace std;

int main() {
    int sum = 0, n, i = 0;
    char str[150] = {0};
    std::cin >> n;
    std::cin >> str;
    while (i != n) {
        sum += (str[i] - '0');
        i++;
    }
    std::cout<<sum;

    return 0;
}