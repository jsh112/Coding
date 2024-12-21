n = int(input())
score = list(map(int, input().split()))

# Maximum score M
# other score k -> k / M * 100

max_score = max(score)

for i in range(n):
    score[i] = score[i] * 100 / max_score # type: ignore

print(sum(score) / n)