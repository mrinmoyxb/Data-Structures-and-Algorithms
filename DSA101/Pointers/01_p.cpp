#include <iostream>

void pointerArray(){
    int arr[5] = {10, 20, 30, 40, 50};

    std::cout<<"address of arr: "<<arr<<std::endl;
    std::cout<<"address of &arr[0]: "<<&arr[0]<<std::endl;
    std::cout<<"address of arr: "<<&arr<<std::endl;
    std::cout<<"value of arr: "<<*arr<<std::endl;
    std::cout<<"value of arr[0]: "<<arr[0]<<std::endl;
    std::cout<<std::endl;

    for(int i=0; i<5; i++){
        std::cout<<"address of "<<arr[i]<<" : "<<&arr[i]<<std::endl;
        std::cout<<"address of "<<arr[i]<<" : "<<arr+i<<std::endl;
        std::cout<<"value of "<<arr[i]<<" : "<<arr[i]<<std::endl;
        std::cout<<"value of "<<arr[i]<<" : "<<*(arr+i)<<std::endl;
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    int* ptr = arr;
    for(int i=0; i<5; i++){
        std::cout<<"address: "<<(ptr+i)<<std::endl;
        std::cout<<"value: "<<*(ptr+i)<<std::endl;
        std::cout<<std::endl;
    }
}

void charArray(){
    char ch[5] = {'a', 'b', 'c', 'd'};
    std::cout<<"Address of char: "<<ch<<std::endl;
    std::cout<<"Address of ch[0]: "<<&ch[0]<<std::endl;
    for(int i=0; i<6; i++){
        std::cout<<"value: "<<ch[i]<<std::endl;
        std::cout<<"address: "<<&ch[i]<<std::endl;
    }
}

int main(){
    charArray();
    return 0;
}