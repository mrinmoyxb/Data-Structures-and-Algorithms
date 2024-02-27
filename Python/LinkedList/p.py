def demo(index, data):
    l = [12, 13, 45, 60, 43]
    size = 5
    print(l)
    if index>0 and index<=size-1:
        for i in range(len(l)):
            if i==index:
                l[i] = data
                print("Replaced")
    print(l)

demo(2, 900)


# def demos(data):
#   l = [12, 13, 45, 60, 43]
#   print(l)

#   copy_l = l[:]  # Create a copy of the list
#   for item in copy_l:  # Loop through the copy
#     if item == data:
#       l.remove(item)  # Remove the item from the original list

# demo(45)