#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    // coordinate, grade, index
    std::vector<std::tuple<int, int, int>> vec(n);

    int num;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        vec[i] = std::make_tuple(num, i, 0);
    }
    std::sort(vec.begin(), vec.end(), [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<0>(a) < std::get<0>(b);
    });
    auto it = vec.begin();
    int low_num = 0;
    while (it != vec.end() - 1) {
        if (std::get<0>(*it) < std::get<0>(*(it + 1))) {
            std::get<2>(*it) = low_num;
            std::get<2>(*(it + 1)) = ++low_num;
        } else {
            std::get<2>(*it) = low_num;
            std::get<2>(*(it + 1)) = low_num;
        }
        it++;
    }

    std::sort(vec.begin(),vec.end(), [](const std::tuple<int,int,int>& a, const std::tuple<int,int,int>& b){
        return std::get<1>(a) < std::get<1>(b);
    });

    for(const auto& v : vec){
        std::cout<<std::get<2>(v)<<" ";
    }

    return 0;
}