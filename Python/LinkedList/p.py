class BinarySearchAlgo:

    def __init__(self, arr):
        self.arr = arr
    
    def binarySearch(self, value):
        start = 0
        end = len(self.arr)-1
        while start<=end:
            mid = start+(end-start)//2
            if self.arr[mid]==value:
                return mid
            elif self.arr[mid]>value:
                end = mid-1
            else:
                start = mid+1
        return -1
#     return found_indexes

# from searchAlgorithmsMb import LinearSearchAlgo
# from searchAlgorithmsMb import BinarySearchAlgo

#l1 = [12, 30, 45, 89, 90]
l2 = [30, 90, 34, 23, 90, 100]
l3 = [12, 13, 14, 15, 16, 17]

l1 = [12, 30, 45, 89, 90]
target = 45

bs = BinarySearchAlgo(l1)
index = bs.binarySearch(target)
if index!=-1:
    print(f"{target}, Found at index: {index}")
else:
    print("Not found!")