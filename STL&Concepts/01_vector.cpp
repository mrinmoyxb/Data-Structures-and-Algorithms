#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dynamicArray(){
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int>::iterator it;

    cout<<"Array : "<<endl;
    for(it = vec.begin(); it!=vec.end(); it++){
        cout<<*it<<endl;
    }

    int size;
    cout<<"Enter size of the array: ";
    cin>>size;
    vector<int> vec1;
    for(int i=0; i<size; i++){
        int element;
        cout<<"Enter element: ";
        cin>>element;
        vec1.push_back(element);
    }

    cout<<"\nThe array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<vec1[i]<<" ";
    }

    int index;
    cout<<"\nEnter index: ";
    cin>>index;
    cout<<vec1.at(index)<<endl;
}

void checkDuplicates(){
    vector<int> vec;
    int size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cout<<"Enter element: ";
        cin>>element;
        vec.push_back(element);
    }

    map<int, int> duplicates;
    map<int, int>:: iterator it;
    for(int i=0; i<size; i++){
        duplicates[vec[i]] = ++duplicates[vec[i]];
    }

    cout<<"Duplicates: "<<endl;
    for(it = duplicates.begin(); it!=duplicates.end(); it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
}

int main(){
    dynamicArray();
    checkDuplicates();
    return 0;
}