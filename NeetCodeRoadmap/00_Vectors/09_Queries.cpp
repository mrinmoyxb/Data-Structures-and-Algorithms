#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    const int N = 1e5 + 10; /* exponent in C++ 10^5*/
    vector<int> v(N, 0); /* size N and all values are initialised to 0*/
    int size, queries;


    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        vec.push_back(element);
    }

    cout<<"The array is: "<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    //! Main Section: 
    for(int i=0; i<size; i++){
        v[vec[i]]++; /*v[vec[i]] = v[vec[i]] + 1*/
    }
    //! 

    cout<<"\nEnter the number of queries: ";
    cin>>queries;

    while(queries--){
        int query;
        cout<<"\nEnter query: ";
        cin>>query;
        cout<<"Number of occurence: "<<v[query]<<endl;
    }

    return 0;
}

//! Key concept
//* value of original vector is the index in the second array