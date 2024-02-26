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
            print(f"Can't insert {data}, Stack Overflow!")
    
    #? Pop/Delete the top element of the stack
    def pop(self):
        if self.top==-1:
            print("Stack Underflow!")
        else:
            self.stack.pop()
    
    #? Top element in the stack
    def peek(self):
        return self.stack[self.top]
    
    #? Number of elements present in the stack 
    def count(self):
        value = len(self.stack)
        return value
    
    def __searchInStack(self, value):
        l = []
        for i in range(len(self.stack)):
            if self.stack[i]==value:
                l.append(i)
        return l
    
    #? Search an element in the stack
    def search(self, value):
        i = self.__searchInStack(value)
        if i!=[]:
            print(f"Found at index: {i}")
        else:
            print("Not found")
    
    #? change the element in the stack at given index
    def change(self, data, index):
        if index>self.size-1:
            print(f"Can't insert {data} at index {index}, Out of range")
        elif index<=self.size-1:
            self.stack[index]=data
        
    
    #? Display all the elements present in the stack
    def show(self):
        print("Stack: ")
        for i in self.stack[::-1]:
            print(i)


s = Stack(5)
s.push(1)
s.push(2)
s.push(3)
s.push(2)
s.push(5)
s.show()
s.change(200, 5)
s.show()