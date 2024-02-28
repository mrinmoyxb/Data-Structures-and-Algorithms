def binarySearch(arr, value):
    found_indexes = []
    start = 0
    end = len(arr)-1
    while start<=end:
        mid = start+(end-start)//2
        if arr[mid]==value:
            return mid
        elif arr[mid]>value:
            end = mid-1
        else:
            start = mid+1
    return found_indexes

