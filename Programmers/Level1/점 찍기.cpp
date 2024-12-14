#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * k, d가 주어지면 좌표 a, b는 사실상 고정
 * (2, 4)가 들어오면
 * sqrt(a^2 + b^2) <= d^2
 * 0 2 4 에서 중복을 허락해서 2개를 뽑는다
 * 3h2 -> C(n+r-1,r) = C(n+r-1. n-1)
 * C(4,2) = 4 * 3 / 2 * 1 = 6
 */

void combination(std::vector<int>& num, long long& cnt, int d) {
    // nHr, n -> num.size() / r -> 2
    // C(n + 1, 2)
    // 0 -> (0 ~ n - 1)
    // 1 -> (1 ~ n - 1)
    // n - 1 -> (1 ~ n - 1)
    for (size_t i = 0; i < num.size(); ++i) {
        long long a = num[i];
        for (size_t j = 0; j < num.size(); ++j) {
            long long b = num[j];
            if (std::sqrt(a * a + b * b) <= d){
                cnt++;
                std::cout <<"<" << a << ", " << b << ">" << '\n';
            }
        }
    }
}

/* long long solution(int k, int d) {
    std::vector<int> num;
    long long i = 0, cnt = 0;
    while (i * k <= d) {
        num.push_back(i * k);
        i++;
    }
    combination(num, cnt, d);
    return cnt;
} */

/* long long solution(int k, int d) {
    long long cnt = 0;
    long long d_squared = (long long)d * d;

    for (long long a = 0; a * k <= d; ++a) {
        long long a_val = a * k;
        long long max_b_squared = d_squared - a_val * a_val;
        long long max_b = (long long)(sqrt(max_b_squared) / k);
        cnt += (max_b + 1);  // 0부터 max_b까지의 개수
    }

    return cnt;
} */
long long solution(int k, int d) {
    long long cnt = 0;
    size_t sqrt_d = (size_t)d*d;
    
    for(size_t a = 0; a *k <= d;++a)
    {
        size_t num = a * k;
        size_t b = sqrt_d - num * num;
        size_t max_b = (size_t)(std::sqrt(b) / k);
        cnt += (max_b + 1);
    }
    return cnt;
}

int main(int argc, char* argv[]) {
    int k, d;
    std::cin >> k >> d;

    std::cout << solution(k, d);

    return 0;
}