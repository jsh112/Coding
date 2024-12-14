#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool find(std::vector<int>& store, int num) {
    if (store.empty()) {
        store.push_back(num);
        return false;
    }
    // binary search
    std::vector<int>::iterator it = std::lower_bound(store.begin(), store.end(), num);

    // find the num value
    if (it != store.end() && *it == num)
        return true;

    store.insert(it, num);
    return false;
}

std::vector<int> solution(std::vector<int> arr, int k) {
    std::vector<int> ans;
    std::vector<int> store_integer;

    for (const auto& num : arr) {
        if (!find(store_integer, num))
            ans.push_back(num);
    }

    if (ans.size() < k) {
        int cnt = k - ans.size();
        ans.insert(ans.end(), cnt, -1);
    }
    if (ans.size() > k) {
        int cnt = ans.size() - k;
        ans.erase(ans.begin() + k, ans.end());
    }
    return ans;
}

int main(int argc, char* argv[]) {
    std::string str_arr;
    std::getline(cin, str_arr);
    std::vector<int> arr;

    std::string num;
    for (char c : str_arr) {
        if (c != ' ')
            num += c;
        else {
            arr.push_back(std::stoi(num));
            num = "";
        }
    }
    if (!num.empty())
        arr.push_back(std::stoi(num));

    int k;
    std::cin >> k;

    std::vector<int> ans = solution(arr, k);
    for (const auto& n : ans)
        std::cout << n << " ";

    return 0;
}
