#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int value){
    for(int i=0; i<size; i++){
        int start = 0;
        int end = size-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(arr[mid]==value){
                return mid;
            }
            else if(arr[mid]>value){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        return -1;
    }

}


int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int array[size];

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    cout<<"The elements are: "<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    int value;
    cout<<"\nEnter the value you want to search: ";
    cin>>value;

    int position = binarySearch(array, size, value);
    if(position==-1){
        cout<<"Not found!!!"<<endl;
    }
    else{
        cout<<"Found!!, at position: "<<position+1<<endl;
    }
    
    return 0;
}