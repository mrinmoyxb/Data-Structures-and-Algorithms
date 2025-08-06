//! Hashmaps: 
//* In Hashmap data structure insertion, deletion and updation takes place at O(1)
//* map: O(logn)
//* unordered_map: O(1)

#include <iostream>
#include <map>
#include <string>
#include <vector>

void unordered_Map(){
    std::unordered_map<std::string, int> map;

    // 1
    std::pair<std::string, int> p = std::make_pair("apple", 3);
    map.insert(p);

    // 2
    std::pair<std::string, int> p1("ball", 2);

    // 3
    map["cat"] = 3;
    
    // search
    std::cout<<"apple: "<<map["apple"]<<std::endl;
    std::cout<<"apple: "<<map.at("apple")<<std::endl;

    // size
    std::cout<<map.size()<<std::endl;

    // check presence
    std::cout<<map.count("apple")<<std::endl;

    // display all elements
    std::cout<<"all key value pairs are: "<<std::endl;
    for(auto i:map){
        std::cout<<"key: "<<i.first<<" , "<<"value: "<<i.second<<std::endl;
    }

}

void unorderedMap(){
    std::unordered_map<std::string, int> map;
    std::vector<std::string> names = {"alex", "bob", "cam"};
    std::vector<int> marks = {100, 83, 90};

    std::cout<<"\nUnordered Map: "<<std::endl;
    for(int i=0; i<names.size(); i++){
        map[names[i]] = marks[i];
    }

    for(auto i: map){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }

    std::cout<<"\nUpdated odd value: "<<std::endl;
    for(int i=0; i<map.size(); i++){
        if(map[names[i]]%2==0){
            continue;
        }else{
            map[names[i]] = map[names[i]]+2;
        }
    }

    for(auto i:map){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }
}

void maxFrequency(std::vector<int> vec){
    std::map<int, int> map;
    for(auto num: vec){
        map[vec[num]]++;
    }

    for(auto i: map){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }

    int max = INT_MIN;
    for(auto i:map){
        if(i.second>max){
            max = i.second;
        }else{
            continue;
        }
    }

    std::cout<<"max frequency: "<<max<<std::endl;
}

int main(){
    unorderedMap();

    std::vector<int> vec = {1, 2, 3, 1, 12, 45, 22, 2, 4, 3, 1};
    maxFrequency(vec);

    return 0;
}
