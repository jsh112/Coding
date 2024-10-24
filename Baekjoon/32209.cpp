#include <iostream>

int main() {
    int t;
    std::cin >> t;
    int prob[2] = {0};

    int flag = 0;
    while (t--) {
        int idx, _prob;
        std::cin >> idx >> _prob;
        if (idx == 1) {
            prob[0] += _prob;
        } else {
            prob[0] -= _prob;
        }

        if (prob[0] < 0)
            flag = 1;
    }
    if (flag)
        std::cout << "Adios";
    else
        std::cout << "See you next month";

    return 0;
}