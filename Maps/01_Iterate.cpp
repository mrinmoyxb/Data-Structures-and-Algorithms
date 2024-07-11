#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void iterate1(){
    map<int, int> m;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<5; i++){
        int element;
        cin>>element;
        m[i] = element;
    }

    cout<<"The map: "<<endl;
    cout<<"Key       Value"<<endl;
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<"         "<<i->second<<endl;
    }
}


void iterate2(){
    map<string,int> m;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<5; i++){
        string key;
        int value;
        cout<<"Enter key: ";
        cin>>key;
        cout<<"Enter value: ";
        cin>>value;
        m[key] = value;
    }

    std::map<string, int> :: iterator it = m.begin();
    map<string, int>::iterator i = m.begin();

    cout<<"\nThe map "<<endl;
    while(it!=m.end()){
        cout<<it->first<<"       "<<it->second<<endl;
        it++;
    }
}

void iterate3(){
    map<int, int> m;

    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<5; i++){
        int element;
        cin>>element;
        m[i] = element;
    }

    cout<<"The elements are: "<<endl;
    for(auto i:m){
        cout<<i.first<<"     "<<i.second<<endl;
    }
 
}

int main(){
    iterate3();
    return 0;
}