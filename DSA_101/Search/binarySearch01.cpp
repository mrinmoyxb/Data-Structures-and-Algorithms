#include <iostream>
#include <map>
#include <vector>

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

int peak(std::vector<int> A){
    int start = 1;
    int end = A.size()-2;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(A[mid-1] < A[mid] && A[mid+1] > A[mid]){
            return mid;
        }
        else if(A[mid-1]<A[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return -1;
}

int singleElement1(std::vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        if(vec[i]!=vec[i+1] && vec[i]!=vec[i-1]){
            return vec[i];
        }
    }
    return -1;
}

int singleElement2(std::vector<int> vec){
    int ans = 0;
    for(int i=0; i<vec.size(); i++){
        ans = ans ^ vec[i];
    }
    return ans;
}

int singleElement3(std::vector<int> arr){
    int start = 0;
    int end = arr.size()-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
            return mid;
        }
        else if(mid%2==0){
            if(arr[mid]==arr[mid-1]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        else if(mid%2!=0){
            if(arr[mid]==arr[mid-1]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
    }

    return -1;
}

int main(){

    int arr[5] = {1, 4, 5, 3, 2};
    std::cout<<"Array: "<<std::endl;

    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }

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
    std::vector<int> vec = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int p = singleElement3(vec);
    std::cout<<"Peak: "<<p<<std::endl;

}