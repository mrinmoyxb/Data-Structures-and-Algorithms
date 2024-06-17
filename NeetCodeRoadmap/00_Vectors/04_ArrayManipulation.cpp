#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int size;

    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"Elements are(Before): "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]==v[j]){
                v[i]=v[j]=-1;
            }
        }
    }

    cout<<"\nElements are(After): "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<"\nUnique elements: "<<endl;
    for(int i=0; i<v.size(); i++){
        if(v[i]!=-1){
            cout<<v[i]<<" ";
        }
    }
    return 0;
}