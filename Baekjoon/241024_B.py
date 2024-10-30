def construct_string(N, K):
    if K >= N:
        return "No", ""
    
    # 문자열 초기화
    S = ["a"] * N
    
    # K만큼 대칭성 조정
    for i in range(K):
        S[N - i - 1] = "b" if S[i] == "a" else "a"
    
    return "Yes", "".join(S)

# 입력 받기
N, K = map(int, input().split())
result, S = construct_string(N, K)

# 결과 출력
print(result)
if result == "Yes":
    print(S)
