#include <iostream>
#include <vector>
#include <string>

void removeDuplicates(std::vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        for(int j=i+1; j<vec.size(); j++){
            if(vec[i]==vec[j]){
                vec.erase(vec.begin()+j);
                break;
            }
        }
    }

    std::cout<<"\nremoval of duplicates: "<<std::endl;
    for(auto i:vec){
        std::cout<<i<<" ";
    }
}

void checkSum(std::vector<int> &vec, int key){
    int left = 0;
    int right = vec.size()-1;
    while(left<=right){
        if(vec[left]+vec[right]==key){
            std::cout<<vec[left]<<" + "<<vec[right]<<" = "<<key<<std::endl;
            break;
        }else{
            left++;
            right--;
        }
    }
}

void reverseString(std::string &word){
    int left = 0;
    int right = word.length()-1;
    while(left<=right){
        std::swap(word[left], word[right]);
        left++;
        right--;
    }
}

int main(){
    std::vector<int> vec = {1, 3, 4, 5, 7, 10};
    //std::cout<<vec.size();
    //removeDuplicates(vec);
    //checkSum(vec, 9);
    std::string word = "elppa";
    reverseString(word);
    std::cout<<word<<std::endl;
    return 0;
}