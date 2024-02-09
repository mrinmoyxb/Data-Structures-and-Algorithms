class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:

    def __init__(self):
        self.head = None
    
    def insertAtHead(self, data):
        newNode = Node(data)
        newNode.next = self.head;
        self.head = newNode
    
    def insertAtTail(self, data):
        newNode = Node(data)
        currentNode = self.head
        while(currentNode.next):
            currentNode = currentNode.next
        currentNode.next = newNode
    
    def displayLinkedList(self):
        print("Linked list: ")
        currentNode = self.head
        while(currentNode):
            print(currentNode.data)
            currentNode = currentNode.next


list = LinkedList()
list.insertAtHead(10)
list.insertAtHead(20)
list.insertAtTail(30)
list.insertAtHead(50)
list.displayLinkedList()