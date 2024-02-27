class Demo:

    def __init__(self):
        print("Class initialised")
    
    @staticmethod
    def help():
        print("insertElement(value): inserts an element in the array")
        print("insertAtIndex(value, index): inserts an element in the array at specific index within the size limit")
        print("deleteElement(value): deletes an element in the array")
        print("searchElement(value): searches for an element in the array, returns the index of the element if found in the array")
        print("replaceElement(index, value): replaces an element at the provided index")
        print("show(): displays the entire array")


d = Demo()
d.help()
#Demo.help()