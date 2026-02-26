#include <stdio.h>
#define MAX 100

void delete(int arr[], int data, int size){
    for(int i=0; i<size; i++){
        if(arr[i]==data){
            int j = i;
            while(j<size){
                arr[j] = arr[j+1];
                j+=1;
            }
            break;
        }
    }

    printf("\nAfter deletion: \n");
    for(int i=0; i<size-1; i++){
        printf("%d ", arr[i]);
    }
}

void merge(){
    int arr1[5] = {1, 5, 6, 10, 12};
    int arr2[3] = {1, 2, 40};

    int arr3[8];
    int i=0;
    int j=0;
    int k=0;
    while(i<5 && j<3){
        if(arr1[i]<=arr2[j]){
            arr3[k++] = arr1[i++];
        }else{
            arr3[k++] = arr2[j++];
        }
    }

    while(i<5){
        arr3[k++] = arr1[i++];
    }

    while(j<3){
        arr3[k++] = arr2[j++];
    }

    printf("Merged arr: \n");
    for(int i=0; i<8; i++){
        printf("%d ", arr3[i]);
    }
}

void mul(){
    int r1, c1, r2, c2;
    printf("Enter the size of r1: ");
    scanf("%d", r1);
    printf("Enter the size of c1: ");
    scanf("%d", c1);

    int m1[r1][c1];

    printf("Enter the size of r2: ");
    scanf("%d", r2);
    printf("Enter the size of c2: ");
    scanf("%d", c2);

    int m2[r2][c2];

    printf("\nEnter elements in m1: ");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    printf("\nEnter elements in m2: ");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d", &m2[i][j]);
        }
    }

    int arr3[r1][c2];
    for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         arr3[i][j] = 0;
      }
   }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            for(int k=0; k<c1; k++){
                arr3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(){
    merge();
    
    return 0;
}