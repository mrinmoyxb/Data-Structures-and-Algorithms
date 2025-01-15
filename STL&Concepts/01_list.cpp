#include <iostream>
#include <vector>
#include <list>
using namespace std;

//! List push back
void list1(){
    std::list<int> l = {100, 200, 300, 400, 500};

    std::cout<<"\nList is: "<<"\n";
    for(const auto& value: l){
        std::cout<<value<<" ";
    }

    int check = true;
    while(check){
        int element, option;
        std::cout<<"\nEnter an element: ";
        std::cin>>element;
        l.push_back(element);

        std::cout<<"You want to add more? ";
        std::cin>>option;
        if(option==0){
            check=false;
        }
    }

    std::cout<<"\nList is: "<<"\n";
    for(const auto& value: l){
        std::cout<<value<<" ";
    }
}

//! List push front
void list2(){
    std::list<int> l = {100, 200, 300, 400, 500};
    for(const auto& value: l){
        std::cout<<value<<" ";
    }

    int check = true;
    while(check){
        int element, option;
        std::cout<<"\nEnter an element: ";
        std::cin>>element;
        l.push_front(element);

        std::cout<<"Want to add more: ";
        std::cin>>option;
        if(option==0){
            check=false;
        }
    }

    std::cout<<"\nList is: "<<"\n";
    for(const auto& value: l){
        std::cout<<value<<" ";
    }
}

//! iterate list
void iterateList(){
    std::list<int> l = {100, 200, 300, 1000};

    std::cout<<"\nIterate 1: "<<"\n";
    for(const auto& value: l){
        std::cout<<value<<" ";
    }

    std::cout<<"\nIterate 2: "<<"\n";
    for(int number: l){
        std::cout<<number<<" ";
    }

    std::cout<<std::endl;

    int front = l.front();
    int last = l.back();
    std::cout<<"First element: "<<front<<" "<<"Last element: "<<last<<std::endl;

    std::cout<<std::endl;

    l.pop_front();
    l.pop_back();

    for(int number: l){
        std::cout<<number<<" ";
    }
}

int main(){

    std::vector<std::list<int>> vec = {{10, 20, 30}, {40, 50, 60}, {100, 200, 300, 400, 500}};
    for(const auto& values: vec){
        for(const auto& value: values){
            std::cout<<value<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Accessing list in vector: "<<"\n";
    auto result = vec[0];
    for(const auto& num: result){
        std::cout<<"Number: "<<num<<"\n";
    }

    return 0;
}