#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//! Insertion in BST
struct Node* insertBST(struct Node* root, int data){
    if(root==NULL){
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(data < root->data){
        root->left = insertBST(root->left, data);
    }else if(data > root->data){
        root->right = insertBST(root->right, data);
    }

    return root;
}

//! Search in BST
struct Node* searchBST(struct Node* root, int key){
    if(root==NULL || root->data == key){
        return root;
    }
    if(key > root->data){
        return searchBST(root->right, key);
    }

    return searchBST(root->left, key);
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

//! delete in BST
struct Node* deleteBST(struct Node* root, int key){
    if(root==NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }

    else{
        if(root->left==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

int linearSearch(int arr[], int key, int size){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }

    return -1;
}

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    

    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==key){
            return 1;
        }
        if(key>arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    return -1;
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nBubble Sort: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int start, int end){
    int mid = start + (end-start)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;

    int first[len1], second[len2];

    int k = start;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }
    for(int j=0; j<len2; j++){
        second[j] = arr[k++];
    }

    int index1 = 0, index2 = 0;
    k = start;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }else{
            arr[k++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[k++] = first[index1++];
    }

    while(index2<len2){
        arr[k++] = second[index2++];
    }
}


int main(){
    int arr[5] = {11, 2, 322, 4, 52};
    bubbleSort(arr, 5);
    return 0;
}


