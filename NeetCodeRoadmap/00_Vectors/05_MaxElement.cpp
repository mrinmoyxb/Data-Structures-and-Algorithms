#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    vector<int> v;

    int size, max=INT_MIN;
    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter elements in the array: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"Elements in the array are: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    for(int i=0; i<v.size(); i++){
        if(max<v[i]){
            max = v[i];
        }
    }

    cout<<"Max element: "<<max<<endl;
    return 0;
}