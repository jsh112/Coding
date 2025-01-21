#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    std::cin >> n >> m;

    int fact[9] = {
        1,
    };

    for (int i = 1; i < 9; i++)
        fact[i] = fact[i - 1] * (i + 1);

    int combi = fact[n - 1] / (fact[m - 1] * fact[n - m - 1]);

    /**
     * 5 3이 들어온다고 가정
     * (5,3) = (4,2) + (3,2) + (2,2)
     * (4,2)는 1제외, (3,2)는 1,2 제외, (2,2)는 1,2,3 제외
     * 반복문을 돌면서 하나씩 제외해나가면 어떨까
     */
    for (int i = 0; i < combi; i++) {
        
    }

    return 0;
}