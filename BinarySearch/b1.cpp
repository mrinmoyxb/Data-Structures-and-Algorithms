#include <iostream>
#include <vector>

int pivot(std::vector<int> v){
    int start = 0;
    int end = v.size()-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(v[mid] > v[mid+1]){
            start = mid+1;
        }else{
            end = mid;
        }
    }
    return v[end];
}


int main(){
    std::vector<int> v = {2, 3, 4, 1, 2};
    std::cout<<pivot(v)<<std::endl;
    return 0;
}