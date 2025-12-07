#include <iostream>

void maxMin(){
    int arr[5] = {10, 20, 5, 90, 83};
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<5; i++){
        if(max<arr[i]){
            max = arr[i];
        }
        if(min>arr[i]){
            min = arr[i];
        }
    }
    std::cout<<"Max: "<<max<<std::endl;
    std::cout<<"Min: "<<min<<std::endl;
}

void sumOfElement(){
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for(int i=0; i<5; i++){
        sum+=arr[i];
    }

    std::cout<<"Sum: "<<sum<<std::endl;
}

void linearSearch(){
    int key = 33;
    int arr[10] = {11, 22, 45, 34, 56, 3, 33, 56, 45, 90};
    for(int i=0; i<10; i++){
        if(key==arr[i]){
            std::cout<<"Key found at position: "<<i+1<<std::endl;
            return;
        }else{
            continue;
        }
    }
    std::cout<<"Not found"<<std::endl;
}

void reverseArray(){
    int arr[5] = {10, 20, 30, 40, 50};
    int start = 0;
    int end = 4;

    std::cout<<"\nArray: "<<std::endl;
    int s = 0;
    int e = 4;
    while(s<=e){
        std::cout<<arr[s]<<" ";
        s++;
    }

    while(start<=end){
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }

    std::cout<<"\nReversed array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    // maxMin();
    // sumOfElement();
    // linearSearch();
    reverseArray();
    return 0;
}