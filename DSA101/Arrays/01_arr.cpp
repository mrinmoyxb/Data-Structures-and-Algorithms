#include <iostream>
#include <map>
#include <set>

//! Max and min elements of an array
void maxMin(){
    int arr[5] = {10, 20, 5, 90, 83};
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<5; i++){
        if(max<arr[i]){
            max = arr[i];
        }
        if(min>arr[i]){
            min = arr[i];
        }
    }
    std::cout<<"Max: "<<max<<std::endl;
    std::cout<<"Min: "<<min<<std::endl;
}

//! Sum of elements of an array
void sumOfElement(){
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for(int i=0; i<5; i++){
        sum+=arr[i];
    }

    std::cout<<"Sum: "<<sum<<std::endl;
}

//! Linear search 
void linearSearch(){
    int key = 33;
    int arr[10] = {11, 22, 45, 34, 56, 3, 33, 56, 45, 90};
    for(int i=0; i<10; i++){
        if(key==arr[i]){
            std::cout<<"Key found at position: "<<i+1<<std::endl;
            return;
        }else{
            continue;
        }
    }
    std::cout<<"Not found"<<std::endl;
}

//! Reverse an array
void reverseArray(){
    int arr[5] = {10, 20, 30, 40, 50};
    int start = 0;
    int end = 4;

    std::cout<<"\nArray: "<<std::endl;
    int s = 0;
    int e = 4;
    while(s<=e){
        std::cout<<arr[s]<<" ";
        s++;
    }

    while(start<=end){
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }

    std::cout<<"\nReversed array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! 1. Swap alternate numbers
void swapAlternates(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<7; i++){
        std::cout<<arr[i]<<" ";
    }

    int size = 7;
    if((size-2)%2==0){
        for(int i=0; i<size; ){
            std::swap(arr[i], arr[i+1]);
            i+=2;
        }
    }else{
        for(int i=0; i<size; ){
            if(i==size-1){
                break;
            }else{
                std::swap(arr[i], arr[i+1]);
                i+=2;
            }
        }
    }


    std::cout<<"\nAlternate swapped: "<<std::endl;
    int count = 1;
    for(int i=0; i<7; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! 2. Swap alternate numbers optimized
void swapAlternatesO(){
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;

    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    for(int i=0; i<5; i+=2){
        if(i+1<size) {
            std::swap(arr[i], arr[i+1]);
        }
    }

    std::cout<<"\nSwapped array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! Unique element in an array
void uniqueElement(){
    int arr[9] = {1, 2, 3, 3, 4, 5, 5, 2, 1};
    int sum = 0;

    for(int i=0; i<9; i++){
        sum = sum ^ arr[i];
    }

    std::cout<<"unique element: "<<sum<<std::endl;
}

//! Checked duplicates of values: 
bool duplicateValues(std::map<int, int> m){
    std::set<int> s;
    for(auto &itr: m){
        s.insert(itr.second);
    }

    if(s.size() == m.size()){
        return 1;
    }else{
        return 0;
    }
}

//! Leetcode:
void uniqueNumOfOccurences(){
    int arr[10] = {12, 12, 12, 90, 90, 34, 45, 34, 34, 34};
    std::map<int, int> m;
    for(int i=0; i<10; i++){
        if(m.count(arr[i])!=0){
            m[arr[i]] = m[arr[i]]+1;
        }else{
            m[arr[i]] = 1;
        }
    }

    std::cout<<"\nMap: "<<std::endl;
    for(auto &it: m){
        std::cout<<it.first<<" : "<<it.second<<std::endl;
    }

    std::cout<<"\nunique: "<<duplicateValues(m);
}

//! find duplicates
void findDuplicates(){
    int arr[5] = {1, 2, 3, 4, 3};
    int value = 0;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(arr[i]==arr[j]){
                value = arr[i];
            }
        }
    }

    std::cout<<"Duplicate value: "<<value<<std::endl;
}

//! another approach
void findDuplicatesO(){
    int arr[5] = {1, 2, 3, 4, 3};
    int ans = 0;
    for(int i=0; i<5; i++){
        ans = ans ^ arr[i];
    }

    for(int i=0; i<5; i++){
        ans = ans^i;
    }
    std::cout<<"ans: "<<ans<<std::endl;
}

//! Array intersection
void arrayIntersection(){
    std::vector<int> v1 = {1, 2, 2, 4, 5};
    std::vector<int> v2 = {1, 2};
    std::vector<int> intersection;

    std::cout<<"\nVector1"<<std::endl;
    for(auto &i: v1){
        std::cout<<i<<" ";
    }

    std::cout<<"\nVector2"<<std::endl;
    for(auto &i: v2){
        std::cout<<i<<" ";
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<v2.size(); j++){
            if(v1[i]==v2[j]){
                intersection.push_back(v2[j]);
                v2.erase(v2.begin()+j);
            }
        }
    }
    
    std::cout<<"\nVector3"<<std::endl;
    for(auto &i: intersection){
        std::cout<<i<<" ";
    }
}

int main(){
    // swapAlternatesO();
    // uniqueNumOfOccurences();
    // findDuplicatesO();
    arrayIntersection();
    return 0;
}