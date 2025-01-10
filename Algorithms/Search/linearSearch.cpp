#include <iostream>

void linearSearch(int *arr, int size, int key){
    for(int i=0; i<size; i++){
        if(*(arr+i)==key){
            std::cout<<"\nFound"<<std::endl;
            break;
        }
    }
}

int main(){
    int* arr = new int[5];
    for(int i=0; i<5; i++){
        int element;
        std::cout<<"Enter element: ";
        std::cin>>element;
        arr[i] = element;
    }
    linearSearch(arr, 5, 200);
    return 0;
}