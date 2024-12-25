import sys
input = sys.stdin.readline  

n = int(input())
stack = []

command_book = {
    "push": lambda x: stack.append(int(x)),
    "pop": lambda: print(stack.pop() if stack else -1),
    "size": lambda: print(len(stack)),
    "empty": lambda: print(1 if not stack else 0),
    "top": lambda: print(stack[-1] if stack else -1)
}

for _ in range(n):
    command = input().split()  
    if command[0] == "push":
        command_book[command[0]](command[1])  
    else:
        command_book[command[0]]()  
