class Node:
    
    #? create a node
    def __init__(self, data):
        self.data  = data
        self.next = None

class SinglyLinkedList:

    def __init__(self):
         self.head = None
    
    #? insert a node at the head of linked list
    def insertAtHead(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
    
    #? insert a node at the tail of the linked list
    def insertAtTail(self, data):
        newNode = Node(data)
        currentNode = self.head
        while(currentNode.next!=None):
            currentNode = currentNode.next
        currentNode.next = newNode
    
    #? insert a node at any position of the linked list
    def insertAtPosition(self, data, position):
        newNode = Node(data)
        currentNode = self.head
        count = 1
        while(count<position-1):
            currentNode = currentNode.next
            count+=1
        newNode.next = currentNode.next
        currentNode.next = newNode

    #* private
    def __findLinkedList(self, data):
        currentNode = self.head
        position = 1
        l = []
        while(currentNode):
            if currentNode.data==data:
                l.append(position)
            position +=1
            currentNode = currentNode.next
        return l
    
    #? search a value in the linked list
    def searchLinkedList(self, data):
        p = self.__findLinkedList(data)
        if p!=[]:
            print(f"Found at position: {p}")
        else:
            print("Not available!")
    
    #? length of the linked list
    def lengthLinkedList(self):
        currentNode = self.head
        count = 0
        while(currentNode!=None):
            count+=1
            currentNode = currentNode.next
        return count
    
    #? delete a node at particular or provided position of the linked list
    def deleteLinkedList(self, position):
        currentNode = self.head
        count = 1
        while(count<position-1):
            currentNode = currentNode.next
            count +=1
        currentNode.next = currentNode.next.next
    
    #? show the complete linked list
    def displayLinkedList(self):
        print("Linked List: ")
        currentNode = self.head
        while(currentNode!=None):
            print(currentNode.data)
            currentNode = currentNode.next
    
    
l = SinglyLinkedList()
l.insertAtHead(10)
l.insertAtHead(20)
l.insertAtPosition(90, 2)
l.insertAtTail(20)
l.displayLinkedList()
print()
l.deleteLinkedList(3)
l.displayLinkedList()