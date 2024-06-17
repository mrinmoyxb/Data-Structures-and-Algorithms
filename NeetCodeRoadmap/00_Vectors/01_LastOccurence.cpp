#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;

    int size, value;
    int index1=0;
    int index2=0;
    cout<<"Enter the size of the vector: ";
    cin>>size;

    cout<<"Enter the elements in the vector: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        vec.push_back(element);
    }

    cout<<"The elements in the vector: "<<endl;
    for(int element:vec){
        cout<<element<<" ";
    }

    cout<<"\nEnter the element you wanna check: ";
    cin>>value;


    //* Approach 1: Beginning to End
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==value){
            index1 = i;
        }
    }
    cout<<"Index Position: "<<index1<<endl;

    //* Approach 2: End to Beginning
    for(int i=vec.size()-1; i>=0; i--){
        if(vec[i]==value){
            index2 = i;
            break;
        }
    }
    cout<<"Index Position: "<<index2<<endl;

    return 0;
}