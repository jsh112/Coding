import sys
input = sys.stdin.readline
n = int(input().rstrip())

queue = []

command_book = {
    "push" : lambda x : queue.append(int(x)),
    "pop" : lambda : print(queue.pop(0) if queue else -1),
    "size" : lambda : print(len(queue)),
    "empty" : lambda : print(1 if not queue else 0),
    "front" : lambda : print(queue[0] if queue else -1),
    "back" : lambda : print(queue[-1] if queue else -1)
}

for _ in range(n):
    command = input().split()
    if command[0] == "push":
        command_book[command[0]](command[1])
    else:
        command_book[command[0]]()
