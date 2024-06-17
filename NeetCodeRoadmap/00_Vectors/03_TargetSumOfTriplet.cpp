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

    cout<<"\nEnter value: ";
    cin>>value;

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                if((v[i]+v[j]+v[k])==value){
                    cout<<"Index1: "<<i<<" Index2: "<<j<<" Index3: "<<k<<endl;
                    pairs++;
                }
            }
        }
    }
    cout<<"Number of pairs: "<<pairs<<endl;

    return 0;
}