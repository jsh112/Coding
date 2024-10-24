#include <iostream>
#include <queue>
#include <vector>

bool allCheck(std::vector<std::vector<int>>& vec, std::pair<int, int>& s, std::pair<int, int>& e) {
    // 첫번째 값
    int first_value = vec[s.first][s.second]; 
    for (int i = s.first; i <= e.first; i++) {
        for (int j = s.second; j <= e.second; j++) {
            if (vec[i][j] != first_value) {
                return false;
            }
        }
    }
    return true;
}

std::pair<int, int> paper(std::vector<std::vector<int>>& vec, std::pair<int, int> start, std::pair<int, int> end) {
    int cnt_white = 0, cnt_blue = 0;

    if (allCheck(vec, start, end)) {
        if (vec[start.first][start.second] == 1)
            return {0, 1};
        else
            return {1, 0};
    }

    int len = (end.first - start.first + 1) / 2;

    std::vector<std::pair<int, int>> tmp;

    tmp.push_back(paper(vec, start, {start.first + len - 1, start.second + len - 1}));
    tmp.push_back(paper(vec, {start.first, start.second + len}, {start.first + len - 1, end.second}));
    tmp.push_back(paper(vec, {start.first + len, start.second}, {end.first, start.second + len - 1}));
    tmp.push_back(paper(vec, {start.first + len, start.second + len}, end));

    for (auto v : tmp) {
        cnt_white += v.first;
        cnt_blue += v.second;
    }

    return {cnt_white, cnt_blue};
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> vec(N, std::vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> vec[i][j];
        }
    }

    std::pair<int, int> ans = paper(vec, {0, 0}, {N - 1, N - 1});
    std::cout << ans.first << '\n';
    std::cout << ans.second << '\n';
    return 0;
}