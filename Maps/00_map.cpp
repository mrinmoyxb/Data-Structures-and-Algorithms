#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    map<int, string> map1;
    map1.insert(pair<int, string>(1, "Alex"));
    map1.insert(pair<int, string>(2, "Bob"));
    map1.insert(pair<int, string>(3, "Seema"));

    for(auto pair: map1){
        cout<<"Key: "<<pair.first<<" , "<<"Value: "<<pair.second<<endl;
    }

    unordered_map<int, string> map2;
    map2.insert(pair<int, string>(1, "A"));
    map2.insert(pair<int, string>(2, "B"));
    map2.insert(pair<int, string>(3, "C"));

    for(auto pair: map2){
        cout<<"Key: "<<pair.first<<" , "<<"Value: "<<pair.second<<endl;
    }
    

    cout<<endl;
    cout<<"Accessing specific element: "<<endl;
    cout<<map1[1]<<endl;

    cout<<endl;
    cout<<"Size of element: "<<map1.size()<<endl;
    return 0;
}