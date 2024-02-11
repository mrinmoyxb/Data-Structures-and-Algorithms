class Stack:

    def __init__(self, size):
        self.size = size
        self.stack = []
        self.top = -1
    
    def push(self, data):
        if(self.size-self.top>1):
            self.top += 1
            self.stack.append(data)
        else:
            print("Stack Overflow")

    def pop(self):
        if(self.top>=0):
            print("Deleted element is: ", self.stack[self.top])
            self.stack.pop()
        else:
            print("Stack Underflow")
        
    
    def display(self):
        print("Stack: ")
        for i in self.stack[::-1]:
            print(i)


s1 = Stack(5)
s1.push(10)
s1.push(20)
s1.push(30)
s1.push(40)
s1.push(50)
s1.display()
s1.pop()
s1.display()


