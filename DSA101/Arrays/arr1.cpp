#include <iostream>
#include <map>
#include <vector>

void maxMin(){
    int max = INT_MIN;
    int min = INT_MAX;
    int arr[5] = {12, 3, 56, 43, 5};
    for(int i=0; i<5; i++){
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }

    std::cout<<"max: "<<max<<std::endl;
    std::cout<<"min: "<<min<<std::endl;
}

int linearSearch(){
    int key = 43;
    int arr[5] = {12, 3, 56, 43, 5}; 
    for(int i=0; i<5; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return -1;
}

void reverseArray(){
    int arr[5] = {12, 3, 56, 43, 5};
    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\nReverse array: "<<std::endl;
    int start = 0;
    int end = 4;
    while(start<=end){
        std::swap(arr[start++], arr[end--]);
    }
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

void swapArr(){
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[6] = {1, 2, 3, 4, 5, 6};
    std::cout<<"Array1: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr1[i]<<" ";
    }

    int i=0;
    int j=i+1;
    int size=5;
    while(i<size && j<size){
        std::swap(arr1[i], arr1[j]);
        i = j+1;
        j = i+1;
    }

    std::cout<<"\nAfter Swap: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr1[i]<<" ";
    }

    i = 0;
    j = i+1;
    size = 6;
    while(i<size && j<size){
        std::swap(arr2[i], arr2[j]);
        i=j+1;
        j=i+1;
    }

    std::cout<<"\nArray2: "<<std::endl;
    for(int i=0; i<6; i++){
        std::cout<<arr2[i]<<" ";
    }

}

void uniqueElementBruteForce(int* arr, int size){
    std::map<int, int> hmap;

    for(int i=0; i<size; i++){
        if(hmap[arr[i]]==0){
            hmap[arr[i]] = 1;
        }else{
            hmap[arr[i]] = hmap[arr[i]]+1;
        }
    }

    for(const auto& pair: hmap){
        std::cout<<pair.first << " => "<<pair.second<<std::endl;
    }
}

void uniqueElement(int* arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        std::cout<<"ans: "<<ans<<", "<<"arr[i]: "<<arr[i]<<std::endl;
        ans = ans ^ arr[i];
        std::cout<<"ans: "<<ans<<", "<<"arr[i]: "<<arr[i]<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<ans<<std::endl;
}

int findDuplicate(int* arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }

    for(int i=1; i<size; i++){
        ans = ans ^ i;
    }

    return ans;
}

void checkIntersection(std::vector<int> v1, std::vector<int> v2){
    int i=0;
    int j=0;

    std::vector<int> result;

    while(i<v1.size() && j<v2.size()){
        if(v1[i]==v2[j]){
            result.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
        else if(v1[i]<v2[j]){
            j++;
        }
    }

    for(int i=0; i<result.size(); i++){
        std::cout<<result[i]<<" ";
    }
}

void removeDuplicates(std::vector<int>& nums) {
        int i=0;
        int j=i+1;
        
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                i+=1;
                nums[i] = nums[j];
            }
        }

        std::cout<<"Unique: "<<i+1<<std::endl;
        i+=1;
        while(i<nums.size()){
            nums[i] = -999;
            i+=1;
        }

        for(int i=0; i<nums.size(); i++){
            std::cout<<nums[i]<<" ";
        }

    }


int main(){
    std::string s = "A man, a plan, a canal: Panama";
    
    return 0;
}