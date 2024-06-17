#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;

    vector<int> v;

    //* Input elements in vector:
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    //* Output in vector using **for loop**: 
    cout<<"Elements in the vector are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;

    //* Output in vector using **while loop**:
    cout<<"Elements in vector array while loop: "<<endl;
    int i=0;
    while(i<v.size()){
        cout<<v[i]<<endl;
        i++;
    }
    cout<<endl;

    //* Output in vector using **For Each**:
     cout<<"Elements in vector array for each: "<<endl;
    for(int element:v){
        cout<<element<<endl;
    }
    cout<<endl;
    return 0;
}