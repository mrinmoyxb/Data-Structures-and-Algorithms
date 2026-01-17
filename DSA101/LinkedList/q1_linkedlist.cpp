#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*& head1, int data){
    Node* newNode = new Node(data);
    Node* current = head1;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head1){
    Node* current = head1;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Q2. Delete mid node using fast and slow pointer
Node* midPreviousNode(Node* head1){
    Node* slow = head1;
    Node* fast = head1;
    Node* prev = NULL;
    while(fast->next!=NULL){
        prev = slow;
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    std::cout<<"\nmid: "<<slow->data<<std::endl;
    std::cout<<"previous mid: "<<prev->data<<std::endl;

    Node* del = slow;
    prev->next = slow->next;
    slow->next = NULL;
    delete del;

    return head1;
}

//! Q3. Mid node using fast and slow pointer
void midNode(Node* head1){
    Node* slow = head1;
    Node* fast = head1;
    while(fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    std::cout<<"\nMid: "<<slow->data<<std::endl;
}

//! Q4. Odd even linked list
Node* oddEvenLinkedList(Node* head1){
    Node* odd = head1;
    Node* even = head1->next;
    Node* evenCpy = head1->next;
    while(even!=NULL && even->next!=NULL){
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenCpy;
    return head1;
}

//! Q5. Cycle in linked list
Node* linkedListCycle(Node* head1){
    Node* slow = head1;
    Node* fast = head1;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }

    if(slow!=fast){
        return NULL;
    }

    Node* p = head1;
    while(p!=slow){
        p = p->next;
        slow = slow->next;
    }
    return p;
}

//! Q6: Linked List generate random number
//* Approach 1
int genRandomNumber(Node* head1){
    std::vector<int> vec;
    Node* current = head1;
    while(current!=NULL){
        vec.push_back(current->data);
        current = current->next;
    }

    int num = vec.size();
    int index = rand()%num;
    return vec[index];
}

//* Approach 2: Reservoir sampling - NOT DONE

//! Q7: Merge two sorted linked list
//* Approach 1:
Node* mergeTwoSorted(Node* head1, Node* head2){
    Node* current1 = head1;
    Node* current2 = head2;
    Node* newList = NULL;
    Node* current = NULL;

    if(newList==NULL){
        if(current1->data >= current2->data){
            newList = new Node(current2->data);
            current = newList;
            current2 = current2->next;
        }else{
            newList = new Node(current1->data);
            current = newList;
            current1 = current1->next;
        }
    }

    while(current1!=NULL && current2!=NULL){
        if(current1->data <= current2->data){
            Node* newNode = new Node(current1->data);
            current->next = newNode;
            current = newNode;
            current1 = current1->next;
        }else{
            Node* newNode = new Node(current2->data);
            current->next = newNode;
            current = newNode;
            current2 = current2->next;
        }
    }

    while(current1!=NULL){
        Node* newNode = new Node(current1->data);
        current->next = newNode;
        current = newNode;
        current1 = current1->next;
    }

    while(current2!=NULL){
        Node* newNode = new Node(current2->data);
        current->next = newNode;
        current = newNode;
        current2 = current2->next;
    }

    return newList;
}

//* Approach 2: Recursion
Node* mergeTwoSortedRecursion(Node* l1, Node* l2){
    if(l1==NULL) return l2;
    if(l1==NULL) return l1;

    if(l1->data <= l2->data){
        l1->next = mergeTwoSortedRecursion(l1->next, l2);
        return l1;
    }else{
        l2->next = mergeTwoSortedRecursion(l1, l2->next);
        return l2;
    }
}

//! Q8: Merge k sorted list


//! swap zeroes to the left
void swapZeroes(int arr[], int size){
    int slow = 0;
    int fast = 0;
    while(fast<size){
        if(arr[fast]!=0){
            std::swap(arr[slow], arr[fast]);
            slow++;
            fast++;
        }else{
            fast++;
        }
    }
}

int main(){
    Node* head1 = new Node(1);
    insertAtTail(head1, 12);
    insertAtTail(head1, 32);
    insertAtTail(head1, 45);
    insertAtTail(head1, 50);
    insertAtTail(head1, 63);
    display(head1);

    Node* head2 = new Node(1);
    insertAtTail(head2, 10);
    insertAtTail(head2, 22);
    insertAtTail(head2, 49);
    insertAtTail(head2, 50);
    insertAtTail(head2, 900);
    display(head2);

    Node* result = mergeTwoSortedRecursion(head1, head2);
    display(result);
    
    return 0;
}