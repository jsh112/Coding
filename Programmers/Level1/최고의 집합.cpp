#include <iostream>
#include <vector>
using namespace std;

std::vector<int> solution(int n, int s) {
}

int main(int argc, char *argv[]) {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> ans = solution(n, s);
    for (auto s : ans)
        std::cout << s << " ";

    return 0;
}