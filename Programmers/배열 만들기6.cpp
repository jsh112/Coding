#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<int> solution(std::vector<int> arr) {
    size_t i = 0;
    std::vector<int> stk;
    while (i < arr.size()) {
        if (!stk.size() || stk.back() != arr[i])
            stk.push_back(arr[i]);
        else if (stk.back() == arr[i])
            stk.pop_back();

        i++;
    }

    if (!stk.size())
        stk.push_back(-1);

    return stk;
}

int main(int argc, char* argv[]) {
    std::vector<int> arr;
    std::string str_arr;

    std::getline(cin, str_arr);

    for (const auto& c : str_arr) {
        if (c != ' ')
            arr.push_back(c - '0');
    }

    std::vector<int> ans = solution(arr);

    for (const auto& a : ans)
        std::cout << a << " ";

    return 0;
}