#include <iostream>
#include <vector>
#include <list>

//! Approach 1
class MyHashMap1{
    private:
    std::vector<int> hashTable;
    int size;
    int getHashValue(int value){
        return value%size;
    }

    public:
    MyHashMap1(){
        size = 1e6+1;
        hashTable.resize(size);
        fill(begin(hashTable), end(hashTable), -1);
    }

    void put(int key, int value){
        hashTable[key] = value;
    }

    int get(int key){
        return hashTable[key];
    }

    void remove(int key){
        hashTable[key] = -1;
    }
};

//! Approach 2
class MyHashMap{
    public:
    std::vector<std::list<std::pair<int, int>>> buckets;
    int size = 1e4;

    MyHashMap(){
        buckets.resize(size);
    }

    //! Put
    void put(int key, int value){
        int bucket_no = key%size;
        auto& chain = buckets[bucket_no];
        for(auto& it: chain){
            if(it.first==key){
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    //! Get
    int get(int key){
        int bucket_no = key%size;
        auto& chain = buckets[bucket_no];
        if(chain.empty()){
            return -1;
        }
        
        for(auto& it: chain){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
        
    }

    //! Remove 
    void remove(int key){
        int bucket_no = key%size;
        auto& chain = buckets[bucket_no];
        for(auto it=chain.begin(); it!=chain.end(); it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
    }

};
int main(){
    MyHashMap myHashMap = MyHashMap();
    myHashMap.put(1, 1); 
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    std::cout<<myHashMap.get(1)<<"\n";    // return 1, The map is now [[1,1], [2,2]]
    std::cout<<myHashMap.get(3)<<"\n";    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    std::cout<<myHashMap.get(2)<<"\n";    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    std::cout<<myHashMap.get(2)<<"\n";    // return -1 (i.e., not found), The map is now [[1,1]]
    return 0;
}