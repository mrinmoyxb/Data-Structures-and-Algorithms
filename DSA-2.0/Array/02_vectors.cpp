#include <iostream>
#include <vector>

//! Iterate vectors
void vec1(){
    std::vector<int> v1 = {10, 20, 30, 40, 50};

    std::cout<<"\nIteration :"<<std::endl;
    for(const int& i : v1){
        std::cout<<i<<" ";
    }

    std::cout<<"\nIteration using iterator: "<<std::endl;
    std::vector<int>::iterator iter;
    for(iter = v1.begin(); iter!=v1.end(); ++iter){
        std::cout<<*iter<<" ";
    }

    std::cout<<"\nIteration: "<<std::endl;
    for(int i: v1){
        std::cout<<i<<" ";
    }
}

//! Modification of vectors;
void vec2(){
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout<<"Vector: "<<std::endl;
    for(const int& i:vec){
        std::cout<<i<<" ";
    }

    std::cout<<"\nPushing two elements 2 and 4: "<<std::endl;
    vec.push_back(2);
    vec.push_back(4);
    std::cout<<"\nVector: "<<std::endl;
    for(const int& i: vec){
        std::cout<<i<<" ";
    }

    std::cout<<"\nAccessing element at index 3: "<<vec.at(3)<<std::endl;
    std::cout<<"\nUpdating element at index 3: "<<std::endl;
    vec.at(3) = 10000;
    std::cout<<"\nVector: "<<std::endl;
    for(const int& i: vec){
        std::cout<<i<<" ";
    }

    std::cout<<"\nRemove the last element: "<<std::endl;
    vec.pop_back();
    for(const int& i: vec){
        std::cout<<i<<" ";
    }
}

//! Common vector operations
void vec3(){
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout<<"Vector is: "<<std::endl;
    for(const int& i: vec){
        std::cout<<i<<" ";
    }

    std::cout<<"First element: "<<vec.front()<<std::endl;
    std::cout<<"Last element: "<<vec.back()<<std::endl;
    std::cout<<"Size of vector: "<<vec.capacity()<<std::endl;
    std::cout<<"Number of elements: "<<vec.size()<<std::endl;
}

int main(){
    vec2();
    vec3();
    return 0;
}