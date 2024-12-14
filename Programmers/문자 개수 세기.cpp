#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<int> solution(std::string str) {
    std::vector<int> ans(52, 0);
    size_t idx;
    for(const char& c : str){
        if(c >= 'A' && c <= 'Z')
            idx = c - 'A';
        else
            idx = c - 'a' + 26;
        ans[idx]++;
    }
    return ans;
}

int main(int argc, char* argv[]) {
    std::string str;
    std::cin >> str;

    std::vector<int> ans = solution(str);

    for (const int& a : ans)
        std::cout << a << " ";

    return 0;
}