#include <iostream>
#include <map>
using namespace std;

void checkPair(){
    std::pair<int, int> p = make_pair(10, 10);
    std::cout<<"First: "<<p.first<<"\n";
    std::cout<<"Second: "<<p.second<<"\n";
}

int main(){
    // map<int, string> sdb;
    // map<int, string>::iterator i;
    // int *arr = new int[5];

    // for(int i=0; i<5; i++){
    //     int id;
    //     string name;
    //     cout<<"Enter id: ";
    //     cin>>id;
    //     cout<<"Enter name: ";
    //     cin>>name;
    //     sdb[id] = name;
    // }

    // for(i = sdb.begin(); i!=sdb.end(); i++){
    //     cout<<i->first<<" : "<<i->second<<endl;
    // }
    checkPair();

    return 0;
}