class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
    
    def insertAtHead(self, data):
        newNode = Node(data)
        temp = self.head
        
        ptr1.next = self.head
        if self.head is not None:
            while(temp.next != self.head):
                temp = temp.next
            temp.next = ptr1
        else:
            ptr1.next = ptr1
        self.head = ptr1

    def display(self):
        temp = self.head
        if self.head is not None:
            while(True):
                print (temp.data, end=" ")
                temp = temp.next
                if (temp == self.head):
                    break

c = CircularLinkedList()
c.insertAtHead(10)
c.insertAtHead(20)
c.insertAtHead(40)
c.insertAtHead(50)
c.display()