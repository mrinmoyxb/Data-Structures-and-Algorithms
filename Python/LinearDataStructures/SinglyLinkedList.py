class Node:
    def __init__(self, data):
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

    def searchLinkedList(self, data):
        p = self.__findLinkedList(data)
        if p!=None:
            print(f"Found at position: {p}")
        else:
            print("Not available!")
    
    def lengthLinkedList(self):
        currentNode = self.head
        count = 0
        while(currentNode!=None):
            count+=1
            currentNode = currentNode.next
        return count
    
    def displayLinkedList(self):
        print("Linked List: ")
        currentNode = self.head
        while(currentNode!=None):
            print(currentNode.data)
            currentNode = currentNode.next
            

        

l = LinkedList()
l.insertAtHead(10)
l.insertAtHead(20)
l.insertAtPosition(90, 2)
l.insertAtTail(20)
l.displayLinkedList()
l.searchLinkedList(20)
l1 = l.lengthLinkedList()
print(l1)