#include <iostream>
#include <vector>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList{

    public:
    Node* linkedList = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* temp = head;

    SinglyLinkedList(int data){
        Node* newNode = new Node(data);
        linkedList = newNode;
        head = linkedList;
        tail = linkedList;
    }

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtMid(int data, int position){
        Node* newNode = new Node(data);
        Node* current = head;
        int count = 1;
        while(count<position-1){
            current = current->next;
            count+=1;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    Node* reverseLinkedList(){
        Node* prev = NULL;
        Node* current = head;
        Node* forward = NULL;
        while(current!=NULL){
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        head = prev;
        return prev;
    }

    int lengthOfLinkedList(){
        int count = 0;
        Node* current = head;
        while(current!=NULL){
            count+=1;
            current = current->next;
        }
        return count;
    }

    std::vector<int> evenNumbers(){
        Node* current = head;
        std::vector<int> evenNumbersList;
        while(current!=NULL){
            if(current->data%2==0){
                evenNumbersList.push_back(current->data);
                current = current->next;
            }
            current = current->next;
        }
        return evenNumbersList;
    }

    Node* deleteNodeByValue(int data){
        Node* prev = NULL;
        Node* current = head;

        while(current!=NULL){
            if(head->data == data){
                Node* delNode = head;
                head = head->next;
                delete delNode;
                current = head;
                prev = current;
                current = current->next;
            }
        
            if(current->data == data){
                Node* delNode = current;
                prev->next = current->next;
                delete delNode;
            }else{
                prev = current;
                current = current->next;
            }
        }
        return head;
    }

    Node* deleteNodeByPosition(int position){
        Node* current = head;
        int count = 1;
        if(position==1){
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }
        else{
            while(count<position-1){
                current = current->next;
                count+=1;
            }
            Node* delNode = current->next;
            current->next = current->next->next;
            delete delNode;
        }
        return head;
    }

    void display(){
        std::cout<<"\nLinked List: "<<"\n";
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    void displayWithNode(Node* head){
        std::cout<<"\nLinked List: "<<"\n";
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

};

int main(){
    SinglyLinkedList s = SinglyLinkedList(100);
    s.insertAtHead(200);
    s.insertAtTail(300);
    s.insertAtTail(200);
    s.insertAtTail(500);
    s.display();

    s.insertAtMid(1000, 2);
    s.display();

    // Node* rev = s.reverseLinkedList();
    // s.displayWithNode(rev);

    // s.display();

    // std::cout<<"\nLength of linked list: "<<s.lengthOfLinkedList()<<"\n";
    // std::vector<int> evenNums = s.evenNumbers();

    // std::cout<<"Even numbers: "<<"\n";
    // for(const auto& num: evenNums){
    //     std::cout<<num<<" ";
    // }

    Node* result = s.deleteNodeByPosition(3);
    s.displayWithNode(result);


    return 0;

}