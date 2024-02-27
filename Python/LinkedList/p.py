class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    
    def insertAtHead(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
    
    def display(self):
        currentNode = self.head
        while(currentNode):
            print(f"currentNode->data:  {currentNode.data}")
            currentNode = currentNode.next

n = LinkedList()
n.insertAtHead("A")
n.insertAtHead(20)
n.insertAtHead("V")
n.insertAtHead(45.6)
n.display()