#include <iostream>
#include <vector>
#include <map>

int majorityElement(std::vector<int>& nums){
    std::map<int, int> result;
    int check = nums.size()/2;
    for(int i=0; i<nums.size(); i++){
        result[nums[i]]+=1;
    }

    int max = INT_MIN;
    int maxElement = 0;
    for(auto& i: result){
        if(i.second > check && i.second > max){
            maxElement = i.first;
        }
    }
    return maxElement;
}

std::pair<int, int> duplicatesMatrix(std::vector<std::vector<int>> &vec){
    // map
    std::map<int, int> result;
    for(auto& i: vec){
        for(auto& j: i){
            result[j]+=1;
        }
    }

    std::cout<<"\nmap: "<<std::endl;
    for(auto& i: result){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }

    // duplicates and missing value
    int max = INT_MIN;
    int maxElement = 0;
    int missing_value = -1;
    int size = vec.size()*vec.size();

    for(auto& i: result){
        if(i.second>max){
            max = i.second;
            maxElement = i.first;
        }
    }

    for(int i=1; i<size+1; i++){
        if(result[i]!=0){
            continue;
        }
        else{
            missing_value = i;
        }
    }

    std::pair<int, int> ans = {maxElement, missing_value};
    return ans;
}

class Solution{
    public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid){
        const int n = grid.size();
        const int nSquared = n*n;
        std::vector<int> count(nSquared+1);

        for(const std::vector<int>& row: grid){
            for(const int num: row){
                count[num]++;
            }
        }

        std::cout<<"array: "<<std::endl;
        for(int i=0; i<count.size(); i++){
            std::cout<<i<<" : "<<count[i]<<std::endl;
        }

        int repeated = -1;
        int missing = -1;

        for(int i=1; i<count.size(); i++){
            if(count[i]==2){
                repeated = i;
            }
            if(count[i]==0){
                missing = i;
            }
        }

        return {repeated, missing};
    }
};

int main(){
    std::vector<std::vector<int>> vec = {{1, 3}, {2, 2}};
    // for(auto& i: vec){
    //     for(auto& j: i){
    //         std::cout<<j<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    // std::pair<int, int> p = duplicatesMatrix(vec);
    // std::cout<<p.first<<" "<<p.second<<std::endl;

    Solution s;
    s.findMissingAndRepeatedValues(vec);
    return 0;
}