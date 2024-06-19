#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void secondMaxElement(vector<int> &v){
    int max = INT_MIN;
    int secondMax = INT_MIN;

    //* finding the max element of the entire array:
    for(int i=0; i<v.size(); i++){
        if(max<v[i]){
            max = v[i];
        }
    }

    //* finding the second max element of the entire array: 
    for(int i=0; i<v.size(); i++){
        if(secondMax<v[i] && v[i]<max){
            secondMax = v[i];
        }
    }
    cout<<"\nMax element in the array: "<<max<<endl;
    cout<<"Second max element in the array: "<<secondMax<<endl;

}

int main(){
    vector<int> v;

    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"The elements are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    secondMaxElement(v);

    return 0;
}