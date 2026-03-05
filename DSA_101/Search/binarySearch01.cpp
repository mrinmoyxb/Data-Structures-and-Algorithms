#include <iostream>
#include <map>

bool binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(arr[mid]==key){
            return 1;
        }

        if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return 0;
}

void firstAndLast(int arr[], int size, int key){
    std::map<int, int> m;

    for(int i=0; i<size; i++){
        if(arr[i]==key){
            std::cout<<i<<std::endl;
            m[i] = arr[i];
        }
    }

    auto first = m.begin();
    std::cout<<"First index: "<<first->first<<std::endl;
    
    if(!m.empty()){
        auto lastElement = std::next(m.begin(), m.size()-1);
        std::cout<<"Last index: "<<lastElement->first<<std::endl;
    }
}

int firstOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int first = -1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key){
            first = mid;
            end = mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    
    return first; 
}

int lastOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int last = -1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            last = mid;
            start = mid+1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return last;
}

int foccur(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int first = -1;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(arr[mid]==key){
            first = mid;
            end = mid-1;
        }else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return first;
}

int loccur(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int last = -1;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(arr[mid]==key){
            last = mid;
            start = mid+1;
        }else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return last;
}

int peak(int arr[], int size){

    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }else{
            end = mid;
        }
    }
    return start;
}

int main(){

    int arr[5] = {1, 4, 5, 3, 2};
    std::cout<<"Array: "<<std::endl;

    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    // std::cout<<std::endl;
    // int f = firstOccurence(arr, 5, 4);
    // int l = lastOccurence(arr, 5, 4);
    // std::cout<<"First: "<<f<<std::endl;
    // std::cout<<"Last: "<<l<<std::endl;

    // std::cout<<std::endl;
    // int f = foccur(arr, 5, 4);
    // int l = loccur(arr, 5, 4);
    // int v = (l-f)+1;
    // std::cout<<"number of values: "<<v<<std::endl;

    std::cout<<std::endl;
    int p = peak(arr, 5);
    std::cout<<"Peak: "<<p<<std::endl;

}