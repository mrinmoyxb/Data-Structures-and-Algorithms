#include <iostream>
#include <vector>

void check1(){
    std::vector<int> x = {1, 2, 3, 4, 5};
    for(int value: x){
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;

    std::vector<int> y(3, 0);
    for(int value: y){
        std::cout<<value<<" ";
    }
}

void check2(){
    std::vector<int> x = {1, 2, 3, 4, 5};
    for(int value: x){
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"size: "<<x.size()<<std::endl;
    std::cout<<"push: ";
    x.push_back(100);
    for(int value: x){
        std::cout<<value<<" ";
    }
    std::cout<<"pop: ";
    for(int value: x){
        std::cout<<value<<" ";
    }
    std::cout<<"front: "<<x.front()<<std::endl;
    std::cout<<"back: "<<x.back()<<std::endl;

    std::cout<<"Index: "<<x.at(3)<<std::endl;
}

void check3(){
    std::vector<int> v = {1, 2, 3, 3, 1};
    int ans = 0;
    for(int value: v){
        ans ^= value;
    }
    std::cout<<"ans: "<<ans<<std::endl;
}

int main(){
    std::vector<int> x = {1, 2, 3, 4, 5};
    for(int value: x){
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;

    std::vector<int> y;
    y.push_back(1);
    y.push_back(2);

    std::cout<<y.size()<<std::endl;
    std::cout<<y.capacity()<<std::endl;

    check3();
    
    return 0;
}