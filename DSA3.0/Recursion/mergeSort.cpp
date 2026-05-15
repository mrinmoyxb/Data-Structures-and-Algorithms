#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int start, int end){
    int mid = start + (end-start)/2;
    int l1 = mid-start+1;
    int l2 = end-mid;
    int arr1[l1], arr2[l2];
    int k=start;
    for(int i=0; i<l1; i++){
        arr1[i] = arr[k++];
    }
    k = mid+1;
    for(int j=0; j<l2; j++){
        arr2[j] = arr[k++];
    }

    int index1 = 0, index2=0;
    k = start;
    while(index1<l1 && index2<l2){
        if(arr1[index1]<arr2[index2]){
            arr[k++] = arr1[index1++];
        }else{
            arr[k++] = arr2[index2++];
        }
    }

    while(index1<l1){
        arr[k++] = arr1[index1++];
    }

    while(index2<l2){
        arr[k++] = arr2[index2++];
    }
}


void mergeSort(std::vector<int>& arr, int start, int end){
    if(start>=end){
        return;
    }
    
    int mid = start + (end-start)/2;

    std::cout<<"left: "<<std::endl;
    std::cout<<"start: "<<start<<std::endl;
    std::cout<<"end: "<<end<<std::endl;
    std::cout<<"mid: "<<mid<<std::endl;
    for(int i=start; i<=mid; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    mergeSort(arr, start, mid);
    std::cout<<std::endl;

    std::cout<<"right: "<<std::endl;
    std::cout<<"start: "<<(mid+1)<<std::endl;
    std::cout<<"end: "<<end<<std::endl;
    std::cout<<"mid: "<<mid<<std::endl;
    for(int i=(mid+1); i<=end; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    mergeSort(arr, mid+1, end);
    std::cout<<std::endl;

    merge(arr, start, end);
    std::cout<<"merge: "<<std::endl;
    std::cout<<"start: "<<start<<std::endl;
    std::cout<<"end: "<<end<<std::endl;
    for(int i=start; i<=end; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

int main(){
    std::vector<int> v = {8, 3, 4, 5, 2};
    mergeSort(v, 0, v.size()-1);
    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" ";
    }
    return 0;
}