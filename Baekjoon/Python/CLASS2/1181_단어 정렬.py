""" 
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로
단, 중복된 단어는 하나만 남기고 제거해야 한다.

첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 
둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어(문자열)가 한 줄에 하나씩 주어진다. 
주어지는 문자열의 길이는 50을 넘지 않는다.

# 1. for i in range(len(sorted_arr)):
if sorted_arr[i] == sorted_arr[i - 1] -> continue

# 2. using tuple -> duplicate removal
{} -> dict()
() -> tuple()
{only values} -> set()
"""

# 입력
N = int(input())
str_arr = {input() for _ in range(N)}

for word in sorted(str_arr, key=lambda x: (len(x), x)):
    print(word)