#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findIndexOfLargestElement(vector<int> &v){
    int max = INT_MIN;
    int index = 0;
    for(int i=0; i<v.size(); i++){
        if(max<v[i]){
            max = v[i];
            index = i;
        }
    }
    return index;
}

int findLargestElement(vector<int> &v){
    int max = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(max<v[i]){
            max = v[i];
        }
    }
    return max;
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

    int indexOfMaxElement = findIndexOfLargestElement(v);
    v[indexOfMaxElement] = -1;

    cout<<"\nThe elements in the array are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    int secondMaxElement = findLargestElement(v);
    cout<<"\nSecond Max Element: "<<secondMaxElement<<endl;

    return 0;
}