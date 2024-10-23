#include <iostream>
#include <vector>

int main() {
    int n, cash;
    std::cin >> n >> cash;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int j = 0, cnt = 0;
    while (j < n && cash >= arr[j])
        j++;
    
    j--;
    int sum = 0;
    while (cash != 0 && j >= 0) {  
        if (arr[j] <= cash) {  
            sum += (cash / arr[j]);
            cash %= arr[j];
        }
        j--;
    }
    
    std::cout << sum << std::endl;

    return 0;
}
