#include <iostream>
#include <list>

void list1(){
    std::list<int> L = {10, 20, 30, 40, 50};
    std::cout<<"Linked List: "<<"\n";
    for(auto& value: L){
        std::cout<<value<<" ";
    }
}

void list2(){
    std::list<int> numbers = {1, 2, 3, 4, 5};
    std::cout<<"\nLinked List: "<<"\n";
    for(int number: numbers){
        std::cout<<number<<" ";
    }
}

void list3(){
    std::list<int> L = {10, 20, 30, 40, 50};
    L.push_front(100);
    L.push_back(1000);
    for(auto& value: L){
        std::cout<<value<<" ";
    }
    std::cout<<"\nFront: "<<L.front()<<"\n";
    std::cout<<"Back: "<<L.back()<<"\n";
    
    L.pop_front();
    L.pop_back();

    for(auto& number: L){
        std::cout<<number<<" ";
    }
}

void list4(){
    std::vector<std::list<int>> L = {{1, 2, 3}, {10, 20, 30}};
    for(const auto& values: L){
        for(const auto& value: values){
            std::cout<<value<<" ";
        }
        std::cout<<"\n";
    }
}

int main() {
    list4();
    return 0;
}
