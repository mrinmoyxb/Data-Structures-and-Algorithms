#include <iostream>
using namespace std;

int main(){
    int arr[5] = {0, 1, 0, 3, 12};

    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(arr[i]==0){
                swap(arr[i], arr[j]);
            }
        }
    }

    cout<<"Array: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}