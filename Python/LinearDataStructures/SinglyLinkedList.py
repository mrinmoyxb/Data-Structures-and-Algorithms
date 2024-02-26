class Node:
    def __init__(self, data):
        self.head = None
        self.data  = data
        self.next = None

class LinkedList:
    def __init__(self):
         self.head = None
    
    def insertAtHead(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
       
    def insertAtTail(self, data):
        newNode = Node(data)
        currentNode = self.head
        while(currentNode.next!=None):
            currentNode = currentNode.next
        currentNode.next = newNode

    def insertAtPosition(self, data, position):
        newNode = Node(data)
        currentNode = self.head
        count = 1
        while(count<position-1):
            currentNode = currentNode.next
            count+=1
        newNode.next = currentNode.next
        currentNode.next = newNode
    
    def displayLinkedList(self):
        print("Linked List: ")
        currentNode = self.head
        while(currentNode):
            print(currentNode.data)
            currentNode = currentNode.next

l = LinkedList()
l.insertAtHead(10)
l.insertAtHead(20)
l.insertAtTail(1000)
l.insertAtPosition(69, 2)
l.displayLinkedList()