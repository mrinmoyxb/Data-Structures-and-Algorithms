#include <iostream>
#include <map>

std::map<int, int> binarySearch(){
    std::vector<int> arr = {12, 14, 18, 19, 24, 29, 32, 44, 80, 100};

    int start = 0;
    int end = arr.size()-1;
    int key = 80;

    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==key){
            std::map<int, int> result;
            result[mid] = key;
            return result;
        }

        else if(key>arr[mid]){
            start = mid+1;
        }

        else {
            end = mid-1;
        }
    }

    std::map<int, int> m;
    m[-1] = key;
    return m;
}

int main(){
    std::map<int, int> r = binarySearch();
    for(auto &i: r){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }


    return 0;
}