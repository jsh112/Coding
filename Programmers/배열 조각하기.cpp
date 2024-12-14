#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * arr = [0, 1, 2, 3, 4, 5]
 * query = [4, 1, 2]
 * 1. q = 4 -> 짝수일 때는 idx [0 ~ 4]까지만 남겨둠
 * arr.erase는 한번만 진행
 * arr.size() -> 6,
 */

std::vector<int> solution(std::vector<int> arr, std::vector<int> query) {
    for (int i = 0; i < query.size(); ++i) {
        if (arr.empty()) break;
        if (i % 2 == 0) {
            arr.erase(arr.begin() + (query[i] + 1), arr.end());
        }
        else
            arr.erase(arr.begin(), arr.begin() + query[i]);
    }

    return arr;
}

int main(int argc, char* argv[]) {
    std::string str_arr, str_query;
    std::getline(cin, str_arr);
    std::getline(cin, str_query);

    std::vector<int> arr, query;

    for (const auto& c : str_arr) {
        if (c != ' ')
            arr.push_back(c - '0');
    }

    for (const auto& c : str_query) {
        if (c != ' ')
            query.push_back(c - '0');
    }

    std::vector<int> ans = solution(arr, query);

    for (const auto& n : ans)
        std::cout << n << " ";

    return 0;
}