#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* std::vector<int> solution(std::vector<int> arr, std::vector<std::vector<int>> q) {
    std::vector<int> ans;
    for (auto it = arr.begin(); it != arr.end(); ++it)
        ans.push_back(*it);

    for (size_t i = 0; i < q.size(); i++) {
        size_t start = q[i][0];
        size_t end = q[i][1];
        size_t k = q[i][2];
        for (; start <= end && start <ans.size(); start++) {
            if (start % k == 0)
                ans[start]++;
        }
    }
    return ans;
} */

std::vector<int> solution(std::vector<int> arr, std::vector<std::vector<int>> q) {
    for (const auto& v : q) {
        for (size_t i = v[0]; i <= v[1]; i++) {
            if (i % v[2] == 0)
                arr[i]++;
        }
    }
    return arr;
}

int main(int argc, char* argv[]) {
    std::string str1, str2;
    int value;

    std::vector<int> arr;
    std::vector<std::vector<int>> queries;

    std::getline(cin, str1);
    std::getline(cin, str2);

    for (const auto& c : str1) {
        if (c != ' ')
            arr.push_back(c - '0');
    }

    int cnt = 0;
    std::vector<int> temp(3, 0);
    for (const auto& c : str2) {
        if (c != ' ') {
            temp[cnt] = (c - '0');
            cnt++;
        }
        if (cnt == 3) {
            queries.push_back(temp);
            cnt = 0;
        }
    }
    std::vector<int> ans = solution(arr, queries);

    for (const auto& n : ans)
        std::cout << n << " ";

    return 0;
}