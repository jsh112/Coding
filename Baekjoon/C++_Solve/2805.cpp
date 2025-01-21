#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    /* int n, m;
    std::cin >> n >> m;
    std::vector<int> tree(n);

    for (int i = 0; i < n; i++)
        std::cin >> tree[i];

    sort(tree.begin(), tree.end());

    int start = 0, end = tree.back();
    int result = 0;

    while (start <= end) {
        long long sum = 0;
        int mid = start + (end - start) / 2;

        for (int h : tree) {
            if (h >= mid)
                sum += (h - mid);
        }

        if (sum >= m) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    std::cout << result << std::endl;

    return 0; */

    char a;
    std::cin>>a;
}