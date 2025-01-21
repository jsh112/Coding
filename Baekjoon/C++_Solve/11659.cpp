#include <iostream>
#include <vector>

/**
 * 시간 부족이 원인
 * 누적합을 사용하면 된다?
 * 1 ~ k까지의 합은 1 ~ (n - 1)의 합과 n ~ k까지의 합으로 나눌 수 있다.
 * 즉, 들어오는 수를 모두 넣은 후 값을 빼서 답을 구한다
 * 시간 복잡도는 입력받는 수 넣을 때 O(N), 구할때 O(1)
 *
 */

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M, num, sum = 0;
    std::cin >> N >> M;
    std::vector<int> vec;

    vec.push_back(0);
    for (int i = 1; i <= N; i++) {
        std::cin >> num;
        sum += num;
        vec.push_back(sum);
    }
    
    // 0, 5, 9, 12, 14, 15
    // 1, 3이 들어오면 12 - 0 : vec[3] - vec[0]
    // 2, 4가 들어오면 14 - 5 : vec[4] - vec[1]
    // a, b가 들어오면 vec[b] - vec[a-1]
    int s, e;
    for(int i=0;i<M;i++){
        std::cin>>s>>e;
        s--;
        int print = vec[e] - vec[s];
        std::cout<<print<<'\n';
    }

    return 0;
}