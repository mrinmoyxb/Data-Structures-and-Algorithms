#include <iostream>
#include <map>

std::map<int, int> hashTable;
int bucketSize = 10;

//! Division Method
//! Algorithm: h(k) = k mod bucksetSize
int divisionMethod(int k, int bucketSize){
    int hashValue = k%bucketSize;
    return hashValue;
}

//! Hash Function
void hashing(){
    std::map<int, int>::iterator it;
    bool check = true;

    while(check){
        int element, choice;
        std::cout<<"Enter element: ";
        std::cin>>element;

        int hashValue = divisionMethod(element, bucketSize);
        hashTable[hashValue] = element;

        std::cout<<"Want to add more? ";
        std::cin>>choice;
        if(choice==0){
            check=false;
        }
    }

    std::cout<<"\nHash Table: "<<"\n";
    for(it = hashTable.begin(); it!=hashTable.end(); ++it){
        std::cout<<it->first<<"     "<<it->second<<"\n";
    }
}

//! Search in hash table: O(n)
void search(int key, int bucketSize){
    int hashValue = divisionMethod(key, bucketSize);
    std::cout<<hashValue<<std::endl;

    auto result = hashTable.find(hashValue);
    if(result != hashTable.end()){
        std::cout<<"Available"<<std::endl;
        std::cout<<result->first<<" "<<result->second;
    }else{
        std::cout<<"Not available";
    }
}

int main(){
    hashing();
    
    int key;
    std::cout<<"\nEnter key: ";
    std::cin>>key;
    
    search(key, bucketSize);
    return 0;
}