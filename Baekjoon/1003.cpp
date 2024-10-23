#include <iostream>
#include <utility>
#include <vector>

/**
 * 다이나믹 프로그래밍
 * 문제에서 N이 40 이하라고 했고 피보나치 수열이므로
 * 미리 40까지 만들어놓고 하나씩 꺼내면 괜찮지 않을까 싶었다
 * 0과 1의 호출 개수를 저장하는 vector<pair<int,int>> ans를 선언
 * 입력값의 숫자들을 미리 vector에 push_back해두고
 * 하나씩 뽑아내면서 first와 second를 출력한다
 */

void fibonacci(std::vector<std::pair<int, int>>& ans) {
    ans[0] = std::make_pair(1, 0);
    ans[1] = std::make_pair(0, 1);

    for (int i = 2; i <= 40; i++) {
        ans[i].first = ans[i - 1].first + ans[i - 2].first;
        ans[i].second = ans[i - 1].second + ans[i - 2].second;
    }
}

int main() {
    int n, tmp;
    std::vector<int> num;
    // 0 ~ 39에서 나오는 0과 1의 개수를 세는 벡터
    std::vector<std::pair<int, int>> ans(41, {0, 0});
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        num.push_back(tmp);
    }
    fibonacci(ans);

    for (int f : num) {
        std::cout << ans[f].first << " " << ans[f].second << '\n';
    }
    return 0;
}