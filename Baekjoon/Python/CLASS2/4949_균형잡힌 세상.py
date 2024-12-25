class Stack():
    def __init__(self):
        self.stack = []
    
    def push(self, c):
        self.stack.append(c)
    
    def pop(self):
        value = None
        if len(self.stack) > 0:
            value = self.stack.pop()
        return value

def world(arr):
    for string in arr:
        st = Stack()
        flag = 0
        for char in string:
            # or문을 문자열을 통해 간소화
            if char in '([':
                st.push(char)
            
            elif char == ']':
                value = st.pop()
                if value is None or value != '[':
                    print("no")
                    flag = 1
                    break
            
            elif char == ')':
                value = st.pop()
                if value is None or value != '(':
                    print("no")
                    flag = 1
                    break
        if flag == 0:
            if len(st.stack) == 0:
                print("yes")
            else:
                print("no")

arr = iter(lambda: input(), ".")
arr = list(arr)

world(arr)

""" for idx, item in enumerate(arr):
    print(idx, item) """