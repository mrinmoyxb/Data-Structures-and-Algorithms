#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hashing{
    vector<list<int>> hashtable;
    int size;

    Hashing(int size){
        this->size = size;
        hashtable.resize(size);
    }

    int hashValue(int value){
        return value%size;
    }

    void addValue(int key){
        int index = hashValue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int index = hashValue(key);
        return find(hashtable[index].begin(), hashtable[index].end(), key);
    }

    void deleteKey(int key){
        int index = hashValue(key);
        hashtable[index].erase(searchKey(key));
    }
    

};

int main(){
    return 0;
}