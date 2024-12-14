#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. [0][0 ~ (n - 2)]
 * 2. [0 ~ (n - 2)][n - 1]
 * 3. [n - 1][(n - 1) ~ 1]
 * 4. [(n - 1) ~ 1][0]
 * 3 -> 2번, 4 -> 2번
 * n -> (n + 1) / 2번 반복
 */

/* std::vector<std::vector<int>> solution(int n) {
    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));

    int i = 1, duration = (n + 1) / 2;
    for (size_t d = 0; d < duration; ++d) {
        int block = n - 1 -d;
        for (int ii = d; ii < block; ++ii)
            ans[d][ii] = i++;
        for (int ii = d; ii < block; ++ii)
            ans[ii][block] = i++;
        for (int ii = block; ii > d; --ii)
            ans[block][ii] = i++;
        for (int ii = block; ii > d; --ii)
            ans[ii][d] = i++;
    }
    if(n % 2 != 0)
        ans[n / 2][n / 2] = n * n;
    return ans;
} */

std::vector<std::vector<int>> solution(int n) {
    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));

    int i = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for (int col = left; col <= right; ++col) ans[top][col] = i++;
        ++top;

        for (int row = top; row <= bottom; ++row) ans[row][right] = i++;
        --right;

        for (int col = right; col >= left; --col) ans[bottom][col] = i++;
        --bottom;

        for (int row = bottom; row >= top; --row) ans[row][left] = i++;
        ++left;
    }
    return ans;
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ans = solution(n);

    for (const auto& col : ans) {
        for (const auto& e : col)
            std::cout << e << " ";
        std::cout << '\n';
    }

    return 0;
}