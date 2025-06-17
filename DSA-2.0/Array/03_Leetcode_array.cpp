#include <iostream>
#include <map>
#include <vector>

//! Map and vectors
void duplicates(){
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

    std::cout<<"\nVector after arranging the unique element: "<<std::endl;
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
    for(const int& num: vec){
        std::cout<<num<<" ";
    }
}

int main(){
    duplicates();
    return 0;
}