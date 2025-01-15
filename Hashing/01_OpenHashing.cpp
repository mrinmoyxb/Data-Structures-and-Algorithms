#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using std::vector, std::list;

class Hashing{
    private:
    vector<list<int>> hashTable;
    int buckets;

    //! Hash function
    int hashFunction(int key){
        return key%buckets;
    }

    public:
    Hashing(int size){
        this->buckets = size;
        hashTable.resize(size);
    }

    //! Add element
    void add(int key){
        int hashValue = hashFunction(key);
        hashTable[hashValue].push_back(key);
    }

    //! Search element 1
    int search(int key){
        int hashValue = hashFunction(key);
        auto result = hashTable[hashValue];

        for(const auto& value: result){
            if(value==key){
                return 1;
            }
        }
        return -1;
    }

    //! Search element 2
    list<int>::iterator search1(int key){
        int hashValue = hashFunction(key);
        return find(hashTable[hashValue].begin(), hashTable[hashValue].end(), key);
    }

    //! Delete key 
    void deleteKey(int key){
        int hashValue = hashFunction(key);
        auto& bucket = hashTable[hashValue];
        for(auto it = bucket.begin(); it!=bucket.end(); ++it){
            if(*it == key){
                bucket.erase(it);
                return;
            }
        }
    }

    //! Display hashtable
    void display(){
        for(int i=0; i<buckets; i++){
            auto bucket = hashTable[i];
            std::cout<<"Hash Value "<<i<<" : ";
            for(const auto& value: bucket){
                std::cout<<value<<" ";
            }
            std::cout<<std::endl;
        }
    }
};

int main(){
    Hashing h1 = Hashing(10);
    h1.add(123);
    h1.add(224);
    h1.add(223);
    h1.add(109);
    h1.display();

    int result = h1.search(223);
    if(result==1){
        std::cout<<"Available"<<std::endl;
    }else{
        std::cout<<"Not avilable"<<std::endl;
    }
    return 0;
}