class Array:
    
    def __init__(self, size):
        self.size = size
        self.arr = []
    
    #? insert an element in the array: 
    def insertElement(self, data):
        if(self.size-len(self.arr)>=1):
            self.arr.append(data)
        else:
            print(f"Can't insert {data} in the given array, out of range")
    
    #? insert at any position in the array
    def insertAtIndex(self, data, index):
        if index>0 and index<=self.size-1:
            self.arr.insert(index, data)
    
    #? delete an element from the array:
    def deleteElement(self, data):
        for i in self.arr:
            if i==data:
                self.arr.remove(i)
                return True
        return False

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
            print("Not found")
        else:
            print(f"Found at indexes: {i}")
    
    #* private 
    def __replace_Element(self, index, value):
        if index>0 and index<=self.size-1:
            for i in range(len(self.arr)):
                if i==index:
                    self.arr[i]=value
                    return True
    
    #? replace an element in the array based on index:
    def replaceElement(self, index, value):
        s = self.__replace_Element(index, value)
        if s==True:
            print("Replaced")
        else:
            print("Index not found")
        
    #? display the array:
    def show(self):
        print("Array: ")
        for i in range(len(self.arr)):
            print(self.arr[i])
    

a = Array(5)
a.insertElement(10)
a.insertElement(20)
a.insertElement(30)
a.insertElement(40)
a.insertElement(50)
a.show()
print()

a.searchAndReplace(2, 900)
a.show()

print()
a.insertAtIndex(3000, 2)
a.show()

