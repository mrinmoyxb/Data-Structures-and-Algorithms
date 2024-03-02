class BubbleSort:

    def __init__(self, arr):
        self.arr = arr
    
    def bubbleSort(self):
        for i in range(len(self.arr)):
            for j in range(0, len(self.arr)-i-1):
                if self.arr[j] > self.arr[j+1]:
                    temp = self.arr[j]
                    self.arr[j] = self.arr[j+1]
                    self.arr[j+1] = temp


data  = [12, 3, 56, 4, 30]
print(data)
b = BubbleSort(data)
b.bubbleSort()
print(data)