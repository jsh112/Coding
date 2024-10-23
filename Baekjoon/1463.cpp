#include <iostream>
using namespace std;

/**
 * 70->69->23->22->11->10->9->3->1
 * 70->69->23->22->11->10->5->4->2->1

50->49->48->24->12->6->3->1
50->25->24->12->6->3->1

100->99->33->11->10->9->3->1
100->50->25->24->12->6->3->1

10->5->4->2->1
10->9->3->1 */

/**
 *  130 -> 65 -> 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
 *  130 -> 129 -> 43 -> 42 -> 14 -> 7 -> 6 -> 3 -> 1
 */

/**
 * 179 -> 178 -> 89 -> 88 -> 44 -> 22 -> 11 -> 10 -> 9 -> 3 -> 1 : 10
 * 179 -> 178 -> 177 -> 59 -> 58 -> 29 -> 28 -> 14 -> 7 -> 6 -> 3 -> 1
 */

/**
 * 16 -> 15 -> 5 -> 4 -> 2 -> 1
 * 16 -> 8 -> 4 -> 2 -> 1
 */

/**
 * N이 들어왔을 때, 2나 3의 배수가 아니면 N--
 * 2나 3의 배수일 때 (N - 1)이 2나 3의 거듭제곱 꼴이라면 N - 1
 * 그게 아니라면 2, 3으로 나누자
 */

int check(int num)
{
    int tmp = num, flag = 0;
    if (num % 2 == 0)
    {
        while (tmp != 1)
        {
            if (tmp % 2 == 0)
                tmp /= 2;
            else
                flag = 1;
        }
        if (!flag)
            return 2;
    }
    tmp = num;
    else
    {
        while (tmp != 1)
        {
            if (tmp % 3 == 0)
                tmp /= 3;
            else
            {
                if (flag)
                    return 0;
            }
        }
    }
    return 3;
}

int main()
{

    int N, cnt = 0, pow_two = 0, pow_thr = 0;
    std::cin >> N;

    while (N != 1)
    {
        if (N % 2 == 0)
        {
            int d = check(N - 1);
            if (d)
                N--;
            else
                N /= 2;
        }
        else if (N % 3 == 0)
        {
            int d = check(N - 1);
            if (d)
                N--;
            else
                N /= 3;
        }
        else
            N--;
        cnt++;
    }

    std::cout << cnt;
    return 0;
}