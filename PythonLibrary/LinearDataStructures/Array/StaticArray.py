class StaticArray:
    
    #? list of all methods with description
    @staticmethod
    def help():
        print("1 -> insertElement(value): inserts an element in the array")
        print("2 -> insertAtIndex(value, index): inserts an element in the array at specific index within the size limit")
        print("3 -> deleteElement(value): deletes an element in the array")
        print("4 -> searchElement(value): searches for an element in the array, returns the index of the element if found in the array")
        print("5 -> replaceElement(index, value): replaces an element at the provided index")
        print("6 -> sortArray(): sorts the entire array in ascending order")
        print("7 -> numberOfElements(): returns number of elements present in the array")
        print("8 -> show(): displays the entire array")

    def __init__(self, size: int):
        self.size = size
        self.arr = []

    def insertElement(self, data):
        if(self.size-len(self.arr)>=1):
            self.arr.append(data)
        else:
            print(f"Can't insert {data} in the given array, out of range")
    
    def insertAtIndex(self, data, index):
        if index>0 and index<=self.size-1:
            self.arr.insert(index, data)
    
    
    def deleteElement(self, data):
        for i in self.arr:
            if i==data:
                self.arr.remove(i)
                return True
        return False

    #! private 
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
    
    #! private 
    def __replace_Element(self, index, value):
        if index>0 and index<=self.size-1:
            for i in range(len(self.arr)):
                if i==index:
                    self.arr[i]=value
                    return True
    
    def replaceElement(self, index, value):
        s = self.__replace_Element(index, value)
        if s==True:
            print("Replaced")
        else:
            print("Index not found")
    
    def sortArray(self):
        try:
            self.arr.sort()
            print()
            return True
        except:
            print("\nOnly integers are allowed ")
            return False
    
    def numberOfElements(self):
        return len(self.arr)

    def show(self):
        print("Array: ")
        for i in range(len(self.arr)):
            print(self.arr[i], end=" ")


a = StaticArray(5)
a.insertElement(100)
a.insertElement(20)
a.insertElement("A")
a.show()
print(f"\n{a.numberOfElements()}")


    


