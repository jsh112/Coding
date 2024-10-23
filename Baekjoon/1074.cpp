#include <iostream>
#include <vector>

int sum = 0;

int pow(int n, int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= n;
    }
    return result;
}

int draw_z(int sz, int goal_row, int goal_col) {
    int status = 0;
    if (sz == 0) {
        return 0;
    } else {
        int half = pow(2, sz - 1);

        if (goal_row >= half)
            status += 2;
        if (goal_col >= half)
            status += 1;

        int factor = pow(half, 2);

        if (status == 1) {
            sum += (factor + draw_z(sz - 1, goal_row, goal_col - half));
        } else if (status == 2) {
            sum += (status * factor + draw_z(sz - 1, goal_row - half, goal_col));
        } else if (status == 3) {
            sum += (status * factor + draw_z(sz - 1, goal_row - half, goal_col - half));
        } else {
            return draw_z(sz - 1, goal_row, goal_col);
        }
    }
    return sum;
}

int main() {
    int sz, row, col;
    std::cin >> sz >> row >> col;

    int result = draw_z(sz, row, col);
    std::cout << result;

    return 0;
}