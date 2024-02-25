def findSum(arr, size, value):
    pointer1 = 0
    pointer2 = size-1
    l = []
    while pointer1<pointer2:
        current_sum = arr[pointer1]+arr[pointer2]
        if current_sum==value:
            return True
        elif current_sum<value:
            pointer1+=1
        else:
            pointer2-=1


size = int(input("Enter the size of the array: "))
array = []
print("Enter the values: ")
for i in range(size):
    array.append(int(input(f"value {i+1}: ")))
print(f"The array is: {array}")
value = int(input("Enter the value: "))
result = findSum(array, size, value)
if result:
    print(f"Found pairs:")
else:
    print("No pair found")




