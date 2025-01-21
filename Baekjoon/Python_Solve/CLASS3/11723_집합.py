""" import sys
input = sys.stdin.readline
M = int(input())

my_set = set()
setting = {x for x in range(1, 21)}
command_dict = {
    "add" : lambda x : my_set.add(x),
    "remove" : lambda x : my_set.discard(x),
    "check" : lambda x : print(1 if x in my_set else 0),
    "toggle" : lambda x : my_set.remove(x) if x in my_set else my_set.add(x),
    "all" : lambda _ : my_set.update(setting),
    "empty" : lambda _ : my_set.clear()   
}

for _ in range(M):
    command = input().split()
    action = command[0]
    
    if action in ["add", "remove", "check", "toggle"]:
        num = int(command[1])
        command_dict[action](num)
    elif action in ["all", "empty"]:
        command_dict[action](None) """
        
print(dir(set.add))  # This will show the methods/attributes of the `add` method
