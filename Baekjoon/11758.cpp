#include <iostream>
using namespace std;

struct Coord {
    int x;
    int y;
};

Coord input[3];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> input[i].x >> input[i].y;
    }

    int cross_product = (input[1].x - input[0].x) * (input[2].y - input[1].y) -
                        (input[1].y - input[0].y) * (input[2].x - input[1].x);

    int res = 0;
    if (cross_product > 0) {
        res = 1;  
    } else if (cross_product < 0) {
        res = -1; 
    }

    cout << res;

    return 0;
}
