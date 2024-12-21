m, n = map(int, input().split())

numbers = list(map(int, input().split()))
    
combinations = [
    [numbers[i], numbers[j], numbers[k]]
    for i in range(len(numbers))
    for j in range(i + 1, len(numbers))
    for k in range(j + 1, len(numbers))
]

my_blackjack = 0

for combi in combinations:
    blackjack = sum(combi)
    if n - blackjack >= 0 and blackjack > my_blackjack:
        my_blackjack = blackjack
    
print(my_blackjack)