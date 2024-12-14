#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr) {
    int row = arr.size();
    int col = arr[0].size();

    if (row > col) {
        for (auto& r : arr) {
            for (size_t i = 0; i < (row - col); ++i) {
                r.emplace_back(0);
            }
        }
    } else if (row < col) {
        std::vector<int> tmp;
        for (size_t i = 0; i < col; i++)
            tmp.emplace_back(0);

        for (size_t i = 0; i < (col - row); i++)
            arr.emplace_back(tmp);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    // std::vector<std::vector<int>> arr = {{0, 1, 2}, {2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    std::vector<std::vector<int>> arr = {{0, 1}, {4, 5}};

    std::vector<std::vector<int>> ans = solution(arr);
    int row = ans.size();
    int col = ans[0].size();

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}