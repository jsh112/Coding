#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void find_pwd(std::vector<std::pair<std::string, std::string>>& table, std::string& site) {
    int left = 0, right = table.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (table[mid].first == site) {
            std::cout << table[mid].second << '\n';
            return;
        } else if (table[mid].first < site) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::string addr, pwd, site;
    // 인덱스순(알아서 정렬)으로 저장된 벡터
    std::vector<std::pair<std::string, std::string>> table(n);

    for (int i = 0; i < n; i++)
        std::cin >> table[i].first >> table[i].second;

    // 알파벳 순으로 정렬
    sort(table.begin(), table.end(), [](const std::pair<std::string, std::string>& a, std::pair<std::string, std::string>& b) {
        return a.first < b.first;
    });

    for (int i = 0; i < m; i++) {
        std::cin >> site;
        find_pwd(table, site);
    }

    return 0;
}