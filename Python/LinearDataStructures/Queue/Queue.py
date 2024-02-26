class Queue:

    def __init__(self, size):
        self.size = size
        self.queue = []
        self.front = -1
        self.rear = -1
    
    def enqueue(self, data):
        if self.rear==self.size-1:
            print("Queue is full")
        else:
            if self.front==-1:
                self.front +=1
            self.rear +=1
            self.queue.append(data)
    
    def dequeue(self):
        if self.front==-1:
            print("Queue is empty")
        else:
            self.front +=1
            if self.front>=self.rear:
                self.front = -1
                self.rear = -1
            
    
    def display(self):
        print("Queue is: ")
        for i in range(self.front, len(self.queue)):
            print(self.queue[i])


q = Queue(3)
q.enqueue(10)
q.enqueue(20)
q.enqueue(100)
q.display()
print()
q.dequeue()
q.display()