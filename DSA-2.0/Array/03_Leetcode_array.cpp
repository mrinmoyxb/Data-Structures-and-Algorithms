#include <iostream>
#include <map>
#include <vector>

//! Map and vectors to find, remove and arrange duplicates
std::vector<int> duplicates(){
    std::map<int, int> dict;
    std::vector<int> vec = {1, 2, 1, 3, 1, 4, 3, 5};

    std::cout<<"Vector: "<<std::endl;
    for(const int& num: vec){
        std::cout<<num<<" ";
    }

    int duplicates = 0;

    for(int i=0; i<vec.size(); i++){
        if(dict[vec[i]] == 1){
            vec.at(i) = -1;
            duplicates+=1;
        }else{
            dict[vec[i]] = 1;
        }
    }

    std::cout<<"\nVector after identifying duplicates: "<<std::endl;
    for(const int& num: vec){
        std::cout<<num<<" ";
    }

    int right, left;
    for(int i=0; i<duplicates; i++){
        for(int i=0; i<vec.size()-1; i++){
            if(vec[i]==-1){
                std::swap(vec[i], vec[i+1]);
            }else{
                continue;
            }
        }
    }
    return vec;
}

//! Calculate unique elements in a vector
int noOfUnqiueElements(std::vector<int> vec){
    std::map<int, int> dict;
    int duplicates = 0;
    for(int i=0; i<vec.size(); i++){
        if(dict[vec[i]]==1){
            vec.at(i) = -1;
            duplicates+=1;
        }else{
            dict[vec[i]]=1;
        }
    }
    return vec.size()-duplicates;
}

int main(){
    //! 1.
    std::vector<int> vec = duplicates();
    std::cout<<"\nVector after arranging the unique element: "<<std::endl;
    for(const int& num:vec){
        std::cout<<num<<" ";
    }

    //! 2.
    std::vector<int> vec1 = {1, 2, 1, 3, 4, 5, 2};
    int unique = noOfUnqiueElements(vec1);
    std::cout<<"\nNumber of unique elements: "<<unique<<std::endl;

    return 0;
}