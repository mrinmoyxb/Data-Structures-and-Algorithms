#include <iostream>
#include <map>
#include <string>

void useMap(){
    std::map<int, std::string> m;
    m[1] = "apple";
    m[2] = "banana";
    m[3] = "grapes";
    m[4] = "lion";
    m[5] = "dog";

    // iterate map
    std::cout<<"\nMap: "<<std::endl;
    for(auto &it: m){
        std::cout<<it.first<<" -> "<<it.second<<std::endl;
    }

    // using iterator
    std::cout<<"\nMap: "<<std::endl;
    for(auto it = m.begin(); it!=m.end(); it++){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }

    // check if key exists
    if(m.count(3)>0){
        std::cout<<"key exists"<<std::endl;
    }else{
        std::cout<<"key doesn't exists"<<std::endl;
    }

    // first and last element
    auto first = m.begin();
    auto end = m.end(); // points to last + 1 element, so no element at end
    std::cout<<"first element "<<first->first<<" : "<<first->second<<std::endl;

    // using insert
    m.insert({6, "camel"});
    std::cout<<"\nMap: "<<std::endl;
    for(auto &it: m){
        std::cout<<it.first<<" : "<<it.second<<std::endl;
    }

    // size() and empty()
    std::cout<<"size: "<<m.size()<<std::endl;
    std::cout<<"empty: "<<m.empty()<<std::endl;
    
    // using erase
    m.erase(m.begin(), m.end());
}

int main(){
    useMap();
    return 0;
}