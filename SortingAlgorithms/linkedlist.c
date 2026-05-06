#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertAtHead(struct Node* head, int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtTail(struct Node* head, int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;

    if(position==1){
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 1;
    struct Node* current = head;
    while(count<position-1){
        current = current->next;
        count+=1;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int key){
    if(head->data == key){
        head = head->next;
        return head;
    }

    struct Node* current = head->next;
    struct Node* prev = head;

    while(current!=NULL){
        if(current->data==key){
            struct Node* temp = current;
            prev->next = current->next;
            free(temp);
        }else{
            prev = current;
            current = current->next;
        }
    }
    return head;
}

void display(struct Node* head){
    struct Node* current = head;
    printf("Linked List: \n");
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

void circularInsert(struct Node** head, struct Node** tail, int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*tail==NULL){
        *head = *tail = newNode;
        newNode->next = *head;
        (*tail)->next = *head;
    }else{
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = *head;
    }
}

void circularInsertTail(struct Node** head, struct Node** tail, int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*tail==NULL){
        *head = *tail = newNode;
        (*tail)->next = *head;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
        (*tail)->next = (*head);
    }
}

void circularDisplay(struct Node** head){
    if(*head==NULL) return;
    struct Node* temp = (*head);
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=*head);
}

int main(){
    // struct Node* head = malloc(sizeof(struct Node));
    // head->data = 100;
    // head->next = NULL;

    struct Node* h1 = malloc(sizeof(struct Node));
    h1->data = 100;
    h1->next = h1;

    struct Node* t1 = h1;

    circularInsert(&h1, &t1, 200);
    circularInsert(&h1, &t1, 300);
    circularDisplay(&h1);

    // head = insertAtTail(head, 300);
    // head = insertAtTail(head, 800);
    // head = insertAtPosition(head, 500, 5);
    // display(head);
    // head = deleteNode(head, 300);
    // display(head);
}