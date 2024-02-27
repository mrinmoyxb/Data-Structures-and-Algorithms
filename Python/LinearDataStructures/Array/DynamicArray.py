class DynamicArray:

    def __init__(self):
        self.arr = []
    
    #? insert elements in dynamic array
    def insertElement(self, data):
        self.arr.append(data)
    
    
    
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
    
    #? Length of the dynamic array
    def lengthOfArray(self):
        return len(self.arr)


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
d.searchElement(900)
print("Length ", d.lengthOfArray())