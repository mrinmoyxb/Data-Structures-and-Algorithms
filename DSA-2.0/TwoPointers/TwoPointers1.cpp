#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> vec){
    int left = 0;
    for(int right=0; right<vec.size(); right++){
        if(vec[right]!=0){
            std::swap(vec[left], vec[right]);
            left++;
        }
    }

    for(auto num: vec){
        std::cout<<num<<" ";
    }
}

void twoPointersApproach(std::vector<int> &vec){
    int left = 0;
    int right = vec.size()-1;
    while(left<=right){
        if(vec[left]==1 && vec[right]==0){
            std::swap(vec[left], vec[right]);
            left++;
            right--;
        }
        if(vec[left]==0){
            left++;
        }
        if(vec[right]==1){
            right--;
        }
    }
}

void evenOdd(std::vector<int> &vec){
    int left = 0;
    int right = vec.size()-1;
    while(left<=right){
        if(vec[left]%2!=0 && vec[right]%2==0){
            std::swap(vec[left], vec[right]);
            left++;
            right--;
        }

        if(vec[left]%2==0){
            left++;
        }

        if(vec[right]%2!=0){
            right--;
        }
    }
}

void arrangeNumbersUsingPtr(std::vector<int> vec){
    int left = 0;
    int right = vec.size()-1;
    std::vector<int> ans_vec;
    while(left<=right){
        if(abs(vec[left])<abs(vec[right])){
            ans_vec.push_back(vec[right]*vec[right]);
            right--;
        }else{
            ans_vec.push_back(vec[left]*vec[left]);
            left++;
        }
    }

    std::cout<<"\narray: "<<std::endl;
    std::reverse(ans_vec.begin(), ans_vec.end());
    for(auto i:ans_vec){
        std::cout<<i<<" ";
    }

}

int main(){
    std::vector<int> vec = {0, 1, 0, 3, 12, 0};
    std::vector<int> vec1 = {1, 1, 0, 0, 1, 0, 1, 0};
    std::vector<int> vec2 = {1, 4, 6, 9, 13};
    std::vector<int> vec3 = {-10, -3, 2, 4, 5};
    // for(auto num: vec){
    //     std::cout<<num<<" ";
    // }

    //moveZeroes(vec);
    //twoPointersApproach(vec1);
    // evenOdd(vec2);
    for(auto num: vec3){
        std::cout<<num<<" ";
    }
    arrangeNumbersUsingPtr(vec3);
    return 0;
}