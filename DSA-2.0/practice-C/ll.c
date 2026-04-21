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

struct Node* deleteNode(struct Node* head, int key){
    if(head==NULL){
        return NULL;
    }

    if(head->data == key){
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* prev = head;
    struct Node* current = head->next;
    while(current!=NULL){
        if(current->data == key){
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
    printf("\nLinked list: \n");
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main(){
    struct Node* head = NULL;
    head = insertAtHead(head, 200);
    head = insertAtHead(head, 90);
    head = insertAtHead(head, 100);
    head = insertAtTail(head, 42);
    head = insertAtTail(head, 1000);
    display(head);

    head = deleteNode(head, 1000);
    display(head);

    return 0;

}