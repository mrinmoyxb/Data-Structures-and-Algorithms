#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int value){
    for(int i=0; i<size; i++){
        if(arr[i]==value){
            return i;
            break;
        }
    }
    return -1;
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
    int key;
    cout<<"\nEnter the value you want to search: ";
    cin>>key;

    int position = linearSearch(array, size, key);
    if(position==-1) cout<<"Not found!!!"<<endl;
    else cout<<"Found at position: "<<position+1<<endl;
    return 0;
}