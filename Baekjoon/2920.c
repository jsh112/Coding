/*
    문제:
    다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. 
    c는 1로, d는 2로, ..., C를 8로 바꾼다.
    1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending, 둘 다 아니라면 mixed 이다.
    연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지, 아니면 mixed인지 판별하는 프로그램을 작성하시오.
    입력:
    첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.
    출력:
    첫째 줄에 ascending, descending, mixed 중 하나를 출력한다.
*/

#include <stdio.h>

int main(){

    int cnt = 0,status = 0;
    int a[8];
    for(int i=0;i<8;i++){
        scanf("%d",&a[i]);
    }

    while(cnt <= 6){
        if((a[cnt] != a[cnt + 1] - 1) && (a[cnt] != a[cnt + 1] + 1)) {
            printf("mixed");
            status = 3;
            break;
        }
        else if(a[cnt] == a[cnt + 1] - 1) status = 1;
        cnt++;
    }

    if(status == 0) printf("descending");
    else if(status == 1) printf("ascending");


    return 0;
}