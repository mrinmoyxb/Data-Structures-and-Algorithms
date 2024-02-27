class DynamicArray:

    #? list of all methods with description
    @staticmethod
    def help():
        print("1 -> insertElement(value): inserts an element in the array")
        print("2 -> insertAtIndex(value, index): inserts an element in the array at specific index within the size limit")
        print("3 -> deleteElement(value): deletes an element in the array")
        print("4 -> searchElement(value): searches for an element in the array, returns the index of the element if found in the array")
        print("5 -> replaceElement(index, value): replaces an element at the provided index")
        print("6 -> sortArray(): sorts the entire array in ascending order")
        print("7 -> lengthOfArray(): returns the length of the array")
        print("8 -> show(): displays the entire array")
    
    def __init__(self):
        self.arr = []
    
    
    def insertElement(self, value):
        self.arr.append(value)

    def insertAtIndex(self, value, index):
        self.arr.insert(index, value)

    def deleteElement(self, value):
        for i in self.arr:
            if i==value:
                self.arr.remove(i)
                return True
    
    #! private 
    def __findElement(self, value):
        l = []
        for i in range(len(self.arr)):
            if self.arr[i]==value:
                l.append(i)
        return l
    
    def searchElement(self, value):
        i = self.__findElement(value)
        if i==[]:
            print(f"\n{value}, not found in the array")
        else:
            print(f"\nFound at indexes: {i}")
    
    #! private 
    def __replace_Element(self, index, value):
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
    
    def lengthOfArray(self):
        return len(self.arr)
    
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