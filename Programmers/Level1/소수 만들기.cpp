#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> Erato(std::vector<int> nums) {
    
}

int solution(std::vector<int> nums) {
    // 숫자 3개를 고르고 소수 판별
    // 에라토스테네스의 체? 사용?
    // nums vector를 asc로 sort하고 가장 큰 세개의 합을 고르고
    // 소수 vector를 만들어서 거기서 찾자.
    int ans = -1;

    // 1. sort
    std::sort(nums.begin(), nums.end());

    // 2. 가장 큰 세 개의 수를 골라서 합함
    int sum = 0;
    for (auto it = nums.end() - 3; it != nums.end(); ++it)
        sum += *it;

    std::vector<int> prime = Erato(nums);

    
}

int main(int argc, char* argv[]) {
    int n = 4;
    std::vector<int> arr(n, 0);
    for (size_t i = 0; i < n; ++i)
        std::cin >> arr[i];

    std::cout << solution(arr);

    return 0;
}