#include <iostream>
using namespace std;

//! "*" can be read as: value at 

void arr(){
    int array[5] = {100, 200, 300, 400, 500};

    //! array == &array == &array[0]
    cout<<"Address of first element using array: "<<array<<endl;
    cout<<"Address of first element using &array: "<<&array<<endl;
    cout<<"Address of first element using &array[0]: "<<&array[0]<<endl;
    cout<<endl;

    //! array[0] == *array
    cout<<"Value at index 0 using array[0]: "<<array[0]<<endl;
    cout<<"Value at index 0 using *array: "<<*array<<endl;
    cout<<endl;

    //! array[1] == *(array + 1)
    cout<<"Value at index 1 using array[1]: "<<array[1]<<endl;
    cout<<"Value at index 1 using 1[array]: "<<1[array]<<endl;
    cout<<"Value at index 1 using *(array + 1): "<<*(array+1)<<endl;
    cout<<"Value at index 1 using *(1 + array): "<<*(1 + array)<<endl;
    cout<<endl;

    cout<<"Accessing address of each element using address operator: "<<endl;
    for(int i=0; i<5; i++){
        cout<<"Address of each element: "<<&array[i]<<endl;
    }

    cout<<endl;
    cout<<"Accessing elements using deference: "<<endl;
    for(int i=1; i<5; i++){
        cout<<"Element at index "<<i<<" : "<<*(array+i)<<endl;
    }

    cout<<endl;
    for(int i=0; i<5; i++){
        cout<<"Accessing element using index[array]: "<<i[array]<<endl;
    }
}

int main(){
    arr();
    return 0;
}