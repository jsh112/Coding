#include <iostream>
using namespace std;

template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    unsigned long long a, b;
    std::cin >> a >> b;

    if (a < b) {
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }
    unsigned long long _g = gcd(a, b);
    // overflow 방지
    unsigned long long lcm = (a / _g) * b;

    std::cout << lcm;

    return 0;
}