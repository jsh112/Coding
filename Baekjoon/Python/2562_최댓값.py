my_list = []
for _ in range(9):
    my_list.append(int(input()))

max, idx = 0, 0

for i in range(len(my_list)):
    if max < my_list[i]:
        max = my_list[i]
        idx = i

print(f'{max}\n{idx}')