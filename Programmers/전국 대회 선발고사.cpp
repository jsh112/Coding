#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * [3, 7, 2, 5, 4, 6, 1]
 * [0, 1, 1, 1, 1, 0, 0]
 * index [2, 4, 3] -> 20403
 */

/* int solution(std::vector<int> rank, std::vector<bool> att) {
    int ans = 0, select_rank = 1;
    // 3개의 값을 저장할 vector
    std::vector<int> tmp;

    while (tmp.size() != 3) {
        for (size_t i = 0; i < rank.size(); ++i) {
            if (rank[i] == select_rank && att[i])
                tmp.push_back(i);
        }
        select_rank++;
    }

    // ans 계산
    int number = 10000;
    for (const auto& n : tmp) {
        ans += (number * n);
        number /= 100;
    }
    return ans;
} */

int solution(std::vector<int> rank, std::vector<bool> attd) {
    std::vector<std::pair<int,int>> std;
    for(size_t i=0;i<rank.size();++i)
        if(attd[i]) std.push_back({i, rank[i]});

    std::sort(std.begin(), std.end(),[](const std::pair<int,int>& a, const std::pair<int, int>& b){
        return a.second < b.second;
    });

    return 10000 * std[0].first + 100 * std[1].first + std[2].first;
}

int main(int argc, char* argv[]) {
    std::string str_rank, str_attd;
    std::vector<int> rank;
    std::vector<bool> attendance;

    // rank 먼저 입력
    std::getline(cin, str_rank);
    std::string num;
    for (const auto& c : str_rank) {
        if (c != ' ')
            num += c;
        else {
            rank.push_back(std::stoi(num));
            num = "";
        }
    }
    if (num != "")
        rank.push_back(std::stoi(num));

    // attendance 입력
    std::getline(cin, str_attd);
    std::string _bool;
    for (const auto& c : str_attd) {
        if (c != ' ')
            _bool += c;
        else {
            if (_bool == "true") {
                attendance.push_back(true);
            } else {
                attendance.push_back(false);
            }
            _bool = "";
        }
    }

    // 마지막 단어 처리
    if (_bool == "true")
        attendance.push_back(true);
    else
        attendance.push_back(false);

    std::cout << solution(rank, attendance);

    return 0;
}