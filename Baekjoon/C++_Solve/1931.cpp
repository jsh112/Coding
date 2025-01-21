#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int N, s, e;
    std::cin >> N;

    std::vector<std::pair<int, int>> time;

    for (int i = 0; i < N; i++) {
        std::cin >> s >> e;
        time.push_back({s, e});
    }

    std::sort(time.begin(), time.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    int MeetingEnd = time[0].second;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (MeetingEnd <= time[i].first) {
            cnt++;
            MeetingEnd = time[i].second;
        }
    }
    std::cout << cnt;
}