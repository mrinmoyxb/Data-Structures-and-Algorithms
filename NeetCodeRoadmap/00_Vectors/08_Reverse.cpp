#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &v){
    int start = 0;
    int end = v.size()-1;

    while(start<=end){
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }

    cout<<"\nReverse Array is: "<<endl;
    for(int elem:v){
        cout<<elem<<" ";
    }
}

int main(){
    vector<int> v;

    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"The elements in the array are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    reverseArray(v);
    return 0;
}