#include <iostream>
using namespace std;

//! Using for loop
void linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            cout<<key<<" is available in the array"<<endl;
            break;
        }
    }
}

//! Using recursion
bool linearSearchRecursion(int arr[], int size, int key){
    if(size==0){
        return false;
    }

    if(*arr==key){
        return true;
    }
    else{
        return linearSearchRecursion(arr+1, size-1, key);
    }
}

int main(){
    int arr[5] = {10, 400, 90, 24, 90};
    int key = 24;
    cout<<"Linear search: "<<endl;
    linearSearch(arr, 5, key);

    cout<<"\nLinear search using recursion: "<<endl;
    int result = linearSearchRecursion(arr, 5, key);
    if(result==1){
        cout<<key<<" is available in the array"<<endl;
    }
    else{
        cout<<"Not available"<<endl;
    }

    return 0;
}