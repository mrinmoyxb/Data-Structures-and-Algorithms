#include <iostream>
#include <util.h>

//! Initialize type 1
void array1(){
    int size;
    std::cout<<"Enter the size of array: "<<std::endl;
    std::cin>>size;
    int arr[size];
    std::cout<<"Enter values: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    std::cout<<"The values in array are: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! Initialize type 2
void array2(){
    int arr[5] = {100};
    std::cout<<"The values in array are: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! Initialize type 3
void array3(){
    int value = 100;
    int arr[5];
    for(int i=0; i<5; i++){
        arr[i] = value;
    }
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! Different Scenarios
void array4(){
    int arr1[5] = {100};
    int arr2[5] = {10, 20};
    int arr3[5] = {10, 20, 30, 40, 50};
    int arr4[5] = {};

    std::cout<<"Array of size 5 but initialized with a single value: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr1[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Array of size 5 but initialized with only two values: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr2[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Printing all elements of an array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr3[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Initialising an array with no values: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr4[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"inserting an element at a speicific index: "<<std::endl;
    arr2[4] = 100;
    for(int i=0; i<5; i++){
        std::cout<<arr2[i]<<" ";
    }
    
}

//! Manipulating array: Pass by reference
void manipulateArray(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = arr[i]*200;
    }

    std::cout<<"\nInside(Array):"<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! Max and min in an array
std::pair<int, int> maxMin(int* arr, int size){
    int max_number = INT_MIN;
    int min_number = INT_MAX;
    for(int i=0; i<size; i++){
        if(arr[i]>max_number){
            max_number = arr[i];
        }

        if(arr[i]<min_number){
            min_number = arr[i];
        }
    }
    std::pair<int, int> result = {max_number, min_number};
    return result;
}

int main(){
    //array1();
    //array2();
    //array3();
    //array4();

    int arr[5] = {10, 20, 30, 40, 500};
    std::cout<<"\nBefore(Array): "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    // manipulateArray(arr, 5);

    // std::cout<<"\nAfter(Array): "<<std::endl;
    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }
    std::pair<int, int> result = maxMin(arr, 5);
    std::cout<<"\nMax number: "<<result.first<<std::endl;
    std::cout<<"Min number: "<<result.second<<std::endl;

    return 0;
}