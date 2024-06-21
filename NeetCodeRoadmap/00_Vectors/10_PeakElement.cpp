//! Question -> : Find peak element: [10, 20, 3, 90, 100]
//* Here 20 is peak element as it is greater than it's neighbour: 10 and 3


//! > Test case 1: [2, 1], return index = 0
//! > Test case 2: [1], return index = 0

#include <iostream>
#include <vector>
using namespace std;

void findPeakElement(vector<int> &v){
    vector<int> temp;
    for(int i=1; i<v.size()-1; i++){
        if(v[i]>v[i+1] && v[i]>v[i-1]){
            temp.push_back(v[i]);
        }
    }
    
    cout<<"\nPeak elements: ";
    for(int i=0; i<temp.size(); i++){
       cout<<temp[i]<<" ";
    }
}

void findPeakElementIndex(vector<int> &v){
    vector<int> temp;
    for(int i=0; i<v.size()-1; i++){
        if(v[i]>v[i+1] && v[i]>v[i-1]){
            temp.push_back(v[i]);
        }
    }

    cout<<"\nPeak elements index: ";
    for(int i=0; i<temp.size(); i++){
       cout<<temp[i]<<" ";
    }
}

int main(){
    vector<int> vec;
    int size;

    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        vec.push_back(element);
    }

    cout<<"Array is: "<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    findPeakElement(vec);
    return 0;
}

