#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for(int i=0;i<n;i++){
        std::cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    std::vector<int> time(n);
    int sum = 0;

    for(int i=0;i<n;i++){
        time[i] = vec[i] + sum;
        sum += vec[i];
    }
    sum = 0;
    for(auto it : time){
        sum += it;
    }

    std::cout<<sum<<std::endl;

    return 0;
}