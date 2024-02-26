class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None

class DoublyLinkedList:

    def __init__(self):
        self.head = None
    
    def insertAtHead(self, data):
        newNode = Node(data)
        newNode.next = self.head
        if self.head:
            self.head.previous = newNode
        self.head = newNode
    
    def insertAtTail(self, data):
        newNode = Node(data)
        currentNode = self.head
        while(currentNode.next!=None):
            currentNode = currentNode.next
        currentNode.next = newNode
        newNode.previous = currentNode
    
    def insertAtPosition(self, data, position):
        newNode = Node(data)
        currentNode = self.head
        count = 1
        while(count<position-1):
            currentNode = currentNode.next
            count+=1
        newNode.next = currentNode.next
        currentNode.next = newNode
        newNode.previous = currentNode
    
    def displayLinkedList(self):
        print("Doubly Linked List: ")
        currentNode = self.head
        while(currentNode!=None):
            print(currentNode.data)
            currentNode = currentNode.next

d = DoublyLinkedList()
d.insertAtHead(10)
d.insertAtHead(20)
d.insertAtTail(900)
d.insertAtPosition(5000, 2)
d.displayLinkedList()

