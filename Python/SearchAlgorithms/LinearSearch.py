def linearSearch(arr, size, value):
    print("Performing Linear Search: ")
    for i in range(size):
        if arr[i]==value:
            print(f"Found at position: {i+1}")
        


n = int(input("Enter the size of array: "))
print("Enter values in the array: ")

array = []

for i in range(n):
    j = int(input(f"value {i+1}: "))
    array.append(j)

print(f"The array is: {array}")
value = int(input("Enter the value you want to search in the array: "))
linearSearch(array, n, value)

