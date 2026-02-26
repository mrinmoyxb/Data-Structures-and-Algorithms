#include <stdio.h>
#define MAX 5

void matrixAdd(){
    int r1, r2, c1, c2;
    printf("Enter the size of row 1: ");
    scanf("%d", &r1);
    printf("Enter the size of column1: ");
    scanf("%d", &c1);

    int m1[r1][c1];

    printf("Enter the size of row 2: ");
    scanf("%d", &r2);
    printf("Enter the size of column2: ");
    scanf("%d", &c2);

    int m2[r2][c2];

    if(r1!=r2 || c1!=c2){
        return;
    }

    printf("Matrix1: \n");

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter an element: ");
            scanf("%d", &m1[i][j]);
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix2: \n");

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter an element: ");
            scanf("%d", &m2[i][j]);
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    int s[r1][c1];
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            s[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf("Sum: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

void replace(){
    int r1, r2, c1, c2;
    printf("Enter the size of row 1: ");
    scanf("%d", &r1);
    printf("Enter the size of column1: ");
    scanf("%d", &c1);

    int m1[r1][c1];

    printf("Matrix1: \n");

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter an element: ");
            scanf("%d", &m1[i][j]);
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    int r, c, v;
    printf("Enter the row number: ");
    scanf("%d", &r);
    printf("Enter the column number: ");
    scanf("%d", &c);
    printf("Enter the value: ");
    scanf("%d", &v);

    r = r-1;
    c = c-1;

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            if(i==r && j==c){
                m1[i][j] = v;
                break;
            }
        }
    }

     for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void deleteRow(){
    int r1, r2, c1, c2;
    printf("Enter the size of row 1: ");
    scanf("%d", &r1);
    printf("Enter the size of column1: ");
    scanf("%d", &c1);

    int m1[r1][c1];

    printf("Matrix1: \n");

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter an element: ");
            scanf("%d", &m1[i][j]);
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    int rn;
    printf("Enter row index: ");
    scanf("%d", &rn);
    for(int i=rn; i<r1; i++){
        for(int j=0; j<c1; j++){
            m1[i][j] = m1[i+1][j];
        }
    }

    for(int i=0; i<r1-1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

int stack[MAX];
int size = 5;
int top=-1;
void push(int data){
    if(top<size-1){
        top+=1;
        stack[top] = data;
    }else{
        printf("Stack overflow");
    }
}

void pop(){
    if(top==-1){
        printf("Stack underflow");
    }else{
        printf("%d is popped", stack[top]);
        top-=1;
    }
}

void peak(){
    if(top==-1){
        return;
    }else{
        printf("Peak is: %d", stack[top]);
    }
}

void print(){
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[top]);
    }
}

int main(){

    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    print();
    printf("\n");
    printf("%d ", stack[1]);
    printf("%d ", stack[2]);

    return 0;
}