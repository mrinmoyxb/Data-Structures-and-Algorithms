#include <iostream>
#include <vector>

//! If we pass an array we can modify it's value and it's visible in main
void check(int* arr, int size){
    for(int i=0; i<size; i++){
        if(*(arr+i)%2==0){
            *(arr+i)=1;
        }else{
            continue;
        }
    }
    
    std::cout<<"\nInside func: "<<std::endl;
    std::cout<<&arr<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<*(arr+i)<<std::endl;
    }
}

//! If we pass a vector we can modify it's value inside a function but it's not visible inside main
void checkVec(std::vector<int> &v){
    std::cout<<"\nInside function"<<std::endl;
    for(int i=0; i<v.size(); i++){
        if(v[i]%2==0){
            v[i] = 100;
        }else{
            continue;
        }
    }
    for(int value: v){
        std::cout<<value<<" ";
    }
}

int main(){
    // int arr[5] = {10, 23, 30, 43, 50};
    // std::cout<<&arr<<std::endl;
    // std::cout<<arr<<std::endl;
    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }
    // check(arr, 5);
    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }

    std::vector<int> vec = {10, 23, 30, 43, 50};
    for(int value: vec){
        std::cout<<value<<" ";
    }
    checkVec(vec);
    for(int value: vec){
        std::cout<<value<<" ";
    }
    return 0;
}