#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<std::string> solution(std::string& s) {
    std::vector<std::string> ans;
    std::string tmp;
    for (const auto& c : s) {
        if (c == ' ') {
            ans.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(c);
        }
    }

    // 마지막 문자열도 넣어줘야함
    if (!tmp.empty())
        ans.push_back(tmp);

    return ans;
}

int main(int argc, char* argv[]) {
    std::string str;
    std::getline(cin, str);
    std::vector<std::string> ans = solution(str);

    for (const auto& s : ans)
        std::cout << s << " ";

    return 0;
}