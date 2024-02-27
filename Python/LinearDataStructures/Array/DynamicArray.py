class DynamicArray:

    def __init__(self):
        self.arr = []
    
    #? insert elements in dynamic array
    def insertElement(self, data):
        self.arr.append(data)

    #? insert at any position in the dynamic array
    def insertAtIndex(self, data, index):
        self.arr.insert(index, data)
    
    #* private 
    def __findElement(self, data):
        l = []
        for i in range(len(self.arr)):
            if self.arr[i]==data:
                l.append(i)
        return l
    
    #? search elements in the array:
    def searchElement(self, data):
        i = self.__findElement(data)
        if i==[]:
            print(f"\n{data}, not found in the array")
        else:
            print(f"\nFound at indexes: {i}")
    
    #* private 
    def __replace_Element(self, index, value):
        for i in range(len(self.arr)):
            if i==index:
                self.arr[i]=value
                return True
                
    #? search and replace element:
    def replaceElement(self, index, value):
        s = self.__replace_Element(index, value)
        if s==True:
            print("Replaced")
        else:
            print("Index not found")
    
    #? length of the dynamic array
    def lengthOfArray(self):
        return len(self.arr)
    
    #? delete an element
    def deleteElement(self, data):
        for i in self.arr:
            if i==data:
                self.arr.remove(i)
                return True

    #? display elements of dynamic array
    def show(self):
        for i in self.arr:
            print(i, end=" ")

d = DynamicArray()
d.insertElement(10)
d.insertElement(20)
d.insertElement(800)
d.insertElement(40)
d.insertElement(50)
d.show()
d.deleteElement(800)
print()
d.show()
print()
d.insertAtIndex(69, 2)
d.show()
d.replaceElement(2, 900)
d.show()