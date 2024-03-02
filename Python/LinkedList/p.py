
arr = [10, 2, 34, 90, 4]
size = len(arr)
for i in range(size):
    print(f"i: {i}")
    for j in  range(0, size-1-i):
        print(f"arr[j]: {arr[j]}")
    print()