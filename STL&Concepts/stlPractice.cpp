#include <iostream>
#include <list>
using namespace std;

void list1(){
    std::list<int> l = {100, 200, 300, 400, 500};
    for(const auto& value: l){
        std::cout<<value<<" ";
    }
}

int main(){
    list1();
    return 0;
}