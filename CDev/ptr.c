#include <stdio.h>
#include <stdlib.h>

void p1(){
    int num = 100;
    int* ptr = &num;

    char c = 'A';
    char* ptr1 = &c;

    printf("value: %d\n", num);
    printf("value: %d\n", *ptr);
    printf("address: %p\n", &num);
    printf("address: %p\n", ptr);
    printf("\n");

    printf("value: %c\n", c);
    printf("value: %c\n", *ptr1);
    printf("address: %p\n", ptr1);
    printf("address: %p\n", &c);
    printf("\n");

    *ptr = 120;
    ptr+=1;

    printf("value: %d\n", num);
    printf("value: %d\n", *ptr);
    printf("address: %p\n", &num);
    printf("address: %p\n", ptr);
    printf("\n");
}

void p2(){
    int arr[5] = {1, 2, 3, 4, 5};

    printf("address of the first element: %p\n", arr);
    int* ptr = arr;

    for(int i=0; i<5; i++){
        printf("address: %p\n", ptr+i);
        printf("value: %d\n", *(ptr+i));
    }
    printf("\n");
    
    for(int i=0; i<5; i++){
        printf("address: %p\n", (arr+i));
        printf("value: %d\n", *(arr+i));
    }
}

void p3(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void p4(){
    int* arr = (int*) malloc(5*sizeof(int));
    for(int i=0; i<5; i++){
        printf("Enter number: ");
        scanf("%d", (arr+i));
    }

    printf("\nArray: \n");
    for(int i=0; i<5; i++){
        printf("value: %d\n", *(arr+i));
    }
}

void p5(){
    FILE *fp = NULL;
    char str[100];

    fp = fopen("data.txt", "w");
    fprintf(fp, "Hello world");
    fclose(fp);

    fp = fopen("data.txt", "r");
    fgets(str, 100, fp);
    printf("Data from file: %s", str);
    fclose(fp);
}

int main(){

    p5();

    return 0;
}