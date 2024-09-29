#include <iostream>
using namespace std;

void twoDimensionalArray(){
    int row = 2;
    int column = 4;
    int array[row][column] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    for(int i=0; i<row; i++){
        for(int k=0; k<column; k++){
            cout<<array[i][k]<<" ";
        }
        cout<<endl;
    }
}

void twoDimensionalArray1(){

    int rows1, rows2, columns1, columns2 = 0;
    cout<<"Enter the number of rows in the matrix1: ";
    cin>>rows1;
    cout<<"Enter the number of columns in the matrix1: ";
    cin>>columns1;
    int arr1[rows1][columns1];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            cin>>arr1[i][j];
        }
    }

    cout<<"The matrix1 is: "<<endl;
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the number of rows in the matrix2: ";
    cin>>rows2;
    cout<<"Enter the number of columns in the matrix2: ";
    cin>>columns2;
    int arr2[rows2][columns2];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            cin>>arr2[i][j];
        }
    }

    cout<<"The matrix2 is: "<<endl;
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    int arr3[rows1][columns2];

    cout<<"Sum of matrix1 and matrix2 is: "<<endl;
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrixMultiplication(){
    int r1, c1, r2, c2 = 0;
    cout<<"Enter the number of rows in matrix1: ";
    cin>>r1;
    cout<<"Enter the number of columns in matrix1: ";
    cin>>c1;

    int matrix1[r1][c1];
    cout<<"Enter elements: ";
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>matrix1[i][j];
        }
    }

    cout<<"Matrix1: "<<endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the number of rows in matrix1: ";
    cin>>r2;
    cout<<"Enter the number of columns in matrix1: ";
    cin>>c2;

    int matrix2[r2][c2];
    cout<<"Enter elements: ";
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin>>matrix2[i][j];
        }
    }

    cout<<"Matrix2: "<<endl;
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }   

    int matrix3[r1][c2];
    int sum = 0;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            for(int k=0; k<r2; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
            sum = 0;
        }
    }

    cout<<"Matrix3: "<<endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            cout<<matrix3[i][j]<<" ";
        }
        cout<<endl;
    }
    

}

int main(){
    matrixMultiplication();
    return 0;
}

