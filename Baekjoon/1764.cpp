#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using VecStrIter = std::vector<std::string>::iterator;
VecStrIter my_binarysearch(VecStrIter l_begin, VecStrIter l_end, std::string &t) {
    while (l_begin < l_end) {
        // 오버플로우 방지
        VecStrIter mid = l_begin + (l_end - l_begin) / 2;

        if (*mid < t)
            l_begin = mid + 1;
        else
            l_end = mid;
    }
    return l_begin;
}

void find_name(std::vector<std::string> &l, std::vector<std::string> &s) {
    int cnt = 0;
    std::vector<std::string> ans;

    for (const std::string &target : s) {
        auto iter = my_binarysearch(l.begin(), l.end(), target);
        if (iter != l.end() && *iter == target) {
            cnt++;
            ans.push_back(target);
        }
    }

    std::cout << cnt << '\n';
    for (const auto &str : ans) {
        std::cout << str << '\n';
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::string name;
    std::vector<std::string> no_listen;
    std::vector<std::string> no_see;
    for (int i = 0; i < N; i++) {
        std::cin >> name;
        no_listen.push_back(name);
    }

    for (int i = 0; i < M; i++) {
        std::cin >> name;
        no_see.push_back(name);
    }

    std::sort(no_listen.begin(), no_listen.end());
    std::sort(no_see.begin(), no_see.end());

    find_name(no_listen, no_see);

    return 0;
}