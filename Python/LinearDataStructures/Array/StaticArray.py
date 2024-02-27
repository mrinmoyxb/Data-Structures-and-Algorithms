class Array:
    
    def __init__(self, size):
        self.size = size
        self.arr = []
    
    def insertElement(self, data):
        if(self.size-len(self.arr)>=1):
            self.arr.append(data)
        else:
            print(f"Can't insert {data} in the given array, out of range")
    
    def deleteElement(self, data):
        for i in range(len(self.arr)):
            if self.arr[i]==data:
                self.arr[i] = ""
                return True
            else:
                return False
            
    def __findElement(self, data):
        l = []
        for i in range(len(self.arr)):
            if self.arr[i]==data:
                l.append(i)
        return l
    
    def searchElement(self, data):
        i = self.__findElement(data)
        if i==[]:
            print("Not found")
        else:
            print(f"Found at indexes: {i}")
        
    
    def show(self):
        print("Array: ")
        for i in range(len(self.arr)):
            print(self.arr[i])
    

a = Array(5)
a.insertElement(1)
a.insertElement(20)
a.insertElement(100)
a.insertElement(90)
a.insertElement(100)
a.show()
print()
#a.insertElement(10000)
#print(a.deleteElement(90))
a.searchElement(100)
a.show()