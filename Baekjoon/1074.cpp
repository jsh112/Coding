#include <iostream>
#include <vector>

int Zdraw(int size, int _row, int _col) {
    if (size == 0)
        return 0;

    int half_size = 1 << (size - 1);
    int area = half_size * half_size;

    int status = (_row >= half_size ? 2 : 0) + (_col >= half_size ? 1 : 0);

    switch (status) {
        case 1:
            return status * area + Zdraw(size - 1, _row, _col - half_size);
        case 2:
            return status * area + Zdraw(size - 1, _row - half_size, _col);
        case 3:
            return status * area + Zdraw(size - 1, _row - half_size, _col - half_size);
        default:
            return Zdraw(size - 1, _row, _col);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int sz, row, col;
    std::cin >> sz >> row >> col;

    int result = Zdraw(sz, row, col);
    std::cout << result << '\n';

    return 0;
}