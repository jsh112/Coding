#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* std::vector<std::string> solution(std::vector<std::string> pictures, int k) {
    std::vector<std::string> ans;

    for (std::string& s : pictures) {
        std::string str;
        for (char& c : s) {
            for (size_t i = 0; i < k; ++i)
                str += c;
        }
        for (size_t i = 0; i < k; ++i)
            ans.push_back(str);
    }
    return ans;
} */

std::vector<std::string> solution(std::vector<std::string> pictures, int k){
    std::vector<std::string> ans;

    for(const std::string& s : pictures){
        std::string Row;
        for(char c : s)
            Row.append(k, c);
        
        ans.insert(ans.end(), k, Row);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> p = {
        "x.x", ".x.", "x.x"};

    std::vector<std::string> ans = solution(p, 3);

    for (const string& s : ans)
        std::cout << s << '\n';

    return 0;
}