#include <iostream>
#include <vector>
using namespace std;

//! Hash Function:  < k  mod sizeOfArray >
int hashFunction(int value, int size){
    int hashValue = value % size;
    return hashValue;
}

int main(){
    vector<int> v;
    bool enterElement = true;

    cout<<"Enter the elements in the array: "<<endl;
    while(enterElement){
        int element;
        char option;
        cout<<"Enter element: ";
        cin>>element;
        v.push_back(element);
        cout<<"Want to enter more(y/n)?: ";
        cin>>option;
        if(option == 'n'){
            enterElement = false;
        }
    }

    cout<<"Elements in the array are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    //! Hash Table : generate the hash value and store the element in that index(index = hash value)
    const int N = 10;
    vector<int> hashTable(10, -1);
    for(int i=0; i<v.size(); i++){
        int hashValue = hashFunction(v[i], N);
        hashTable[hashValue] = v[i];
    }

    cout<<"\nHash Table: "<<endl;
    for(int i=0; i<hashTable.size(); i++){
        cout<<i<<" : "<<hashTable[i]<<endl;
    }

    return 0;
}