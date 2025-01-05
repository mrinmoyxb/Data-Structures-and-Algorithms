#include <iostream>
#include <map>
using namespace std;

void findDuplicates(int *arr, int size){
    map<int, int> duplicates;
    map<int, int>::iterator iter;

    cout<<"Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<*(arr+i)<<" ";
    }

    for(int i=0; i<size; i++){
        duplicates[arr[i]] = duplicates[arr[i]]+1;
    }

    cout<<"\nElements and number of duplicates: "<<endl;
    for(iter=duplicates.begin(); iter!=duplicates.end(); iter++){
        cout<<iter->first<<" ---- "<<iter->second<<endl;
    }

    auto result = duplicates.find(100);
    cout<<"Result: "<<result->second<<endl;
}

int main(){
    //* Map 1
    map<int, string> sdb1;

    //* Insert method 1:
    sdb1[1] = "Alex";
    sdb1[2] = "Bob";

    //* Insert method 2: 
    sdb1.insert(make_pair(3, "Cam"));

    //* Map 2
    map<int, string> sdb2 = {{1, "James"}, {2, "Hue"}};

    //* Iterating map 1
    cout<<"\nUsing for loop: "<<endl;
    for(int i=1; i<=sdb1.size(); i++){
        cout<<"student "<<i<<" : "<<sdb1[i]<<endl;
    }

    //* Using Iterator
    cout<<"\nUsing iterator: "<<endl;
    map<int, string>::iterator iter;

    for(iter = sdb1.begin(); iter!=sdb1.end(); iter++){
        cout<<iter->first<<"  ----  "<<iter->second<<endl;
    }

    int *arr = new int[5];
    for(int i=0; i<5; i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    findDuplicates(arr, 5);
    delete []arr;
    return 0;
}