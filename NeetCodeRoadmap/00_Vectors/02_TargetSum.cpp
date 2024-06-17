#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v;
    int size, value, pairs=0;
    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"Elements in the array are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<"\nEnter the value: ";
    cin>>value;

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if((v[i]+v[j])==value){
                cout<<"Index1: "<<i<<" Index2: "<<j<<endl;
                pairs++;
            }
        }
    }

    cout<<"Total number of pairs: "<<pairs<<endl;

    return 0;
}