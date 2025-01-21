#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
int BinarySearch(T& name, std::string& s) {
    int left = 0;
    int right = name.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (name[mid].first == s) {
            return name[mid].second;
        } else if (name[mid].first < s) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void print_pocket(T& name, T& number, std::string& s) {
    // number
    if (isdigit(s[0])) {
        int idx = std::stoi(s);
        std::cout << number[idx-1].first << '\n';
        return;
    }
    // string
    else {
        int res = BinarySearch(name, s);
        if (res != -1) {
            std::cout << res << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m;
    std::cin >> n >> m;
    std::string s;
    // 이름순으로 저장할 벡터
    std::vector<std::pair<std::string, int>> name(n);
    // 인덱스순(알아서 정렬)으로 저장된 벡터
    std::vector<std::pair<std::string, int>> number(n);

    for (int i = 0; i < n; i++) {
        std::cin >> s;
        name[i] = {s, i + 1};
        number[i] = {s, i + 1};
    }
    // 알파벳 순으로 정렬
    // 대문자로 보통 시작하지만 소문자인 경우는 뒤로 감
    sort(name.begin(), name.end());

    for (int i = 0; i < m; i++) {
        std::cin >> s;
        print_pocket(name, number, s);
    }

    return 0;
}