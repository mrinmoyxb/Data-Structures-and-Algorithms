class Stack:

    def __init__(self, size):
        self.size = size
        self.stack = []
        self.top = -1
    
    #? Push/Insert an element in the stack
    def push(self, data):
        if self.size-self.top>1:
            self.top +=1
            self.stack.append(data)
        else:
            print("Stack Overflow!")
    
    #? Popped/Delete the top element of the stack
    def pop(self):
        if self.top==-1:
            print("Stack Underflow!")
        else:
            self.stack.pop()

    #? Display elements present in the stack
    def show(self):
        print("Stack: ")
        for i in self.stack[::-1]:
            print(i)
    
    #? Number of elements present in the stack 
    def count(self):
        value = len(self.stack)
        return value

s = Stack(5)
s.push(1)
s.push(2)
s.push(3)
s.show()
print("Count: ",s.count())
s.pop()
s.show()
print("Count: ",s.count())