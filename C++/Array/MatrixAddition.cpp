#include <iostream>
using namespace std;

void matrixAddition(){
    int r1, r2, c1, c2;
    cout<<"Enter the number of rows for array1: ";
    cin>>r1;
    cout<<"Enter the number of columns for array1: ";
    cin>>c1;
    int array1[r1][c1];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>array1[i][j];
        }
    }
    cout<<"The elements are: "<<endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout<<array1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the number of rows for array2: ";
    cin>>r2;
    cout<<"Enter the number of columns for array2: ";
    cin>>c2;
    int array2[r2][c2];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin>>array2[i][j];
        }
    }
    cout<<"The elements are: "<<endl;
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cout<<array2[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum[r1][c1];
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            sum[i][j] = array1[i][j]+ array2[i][j];
        }
    }

    cout<<"Addition of matrix: "<<endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    matrixAddition();
    return 0;
}